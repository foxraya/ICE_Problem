#include <iostream>
#include <fstream>
#include <string>

void printEntries(std::string price, std::string cusip)
{
  // print last price if exists, then cusip
  if (!price.empty())
    std::cout << price << std::endl;
  std::cout << cusip << std::endl;
}

int main() {
  std::ifstream input("test.txt");
  std::string line;
  std::string current;
  while (std::getline(input, line)) {
    std::string::size_type sz;
    if (!line.empty()) {
      try {
        float price = std::stof(line, &sz);
        if (sz == line.size()) {
          // full line parsed as float, save valid price
          current = line;
        }
        else {
          // cusip started with numeric, partially parsed
          printEntries(current, line);
        }
      }
      catch (...) {
        // cusip started with string, failed parse
        printEntries(current, line);
      }
    }
  }
  // print last remaining price
  std::cout << current << std::endl;
  
  return 0;
}
