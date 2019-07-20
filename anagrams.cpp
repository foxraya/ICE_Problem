#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

void getAllWords(std::string filePath, std::vector<std::string> &list)
{
  // Read given block of words to split into our vector
  std::ifstream input(filePath.c_str());
  std::string line;
  
  while (std::getline(input, line)) {
    // Expecting file with lines of words space separated
    if (!line.empty()) {
      std::stringstream wordlist(line);
      std::string word;
      while (std::getline(wordlist, word, ' '))
        list.push_back(word);
    }
  }
}

void printAnagrams(std::unordered_map<std::string, std::vector<std::string> > &store)
{
  // iterate through our store to find the groups to print
  std::unordered_map<std::string, std::vector<std::string> >::iterator it;
  for (it = store.begin(); it != store.end(); ++it) {
    std::vector<std::string> temp(it->second);
    int size = temp.size();
    if (size > 1) {
      // Anagrams to print out (keys of size 1 are solitary words)
      for (int i=0; i < size; ++i) {
        std::cout << temp[i] << " ";
      }
      std::cout << std::endl;
    }
  }
}

void getAnagrams(std::vector<std::string> &list)
{
  // Using Hashmap to store sorted string as key to match
  std::unordered_map<std::string, std::vector<std::string> > store;
  for (int i=0; i < list.size(); ++i) {
    std::string temp(list[i]);
    std::sort(temp.begin(), temp.end());

    // see if it exists in our store
    if (store.find(temp) == store.end()) {
      // new key
      std::vector<std::string> add;
      add.push_back(list[i]);
      // add pair of sorted string, start string
      store.insert(make_pair(temp, add));
    }
    else {
      // existing key
      std::vector<std::string> add(store[temp]);
      // add source string to list with key of its sorted string
      add.push_back(list[i]);
      store[temp] = add;
    }
  }

  // print out all our Anagrams
  printAnagrams(store);
}

int main() {
  std::vector<std::string> wordList;
  getAllWords("words.txt", wordList);
  getAnagrams(wordList);

  return 0;
}
