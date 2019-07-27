using System;

namespace HandleLatest
{
    class Program
    {
        void HandleInput(String fileName)
        {
            using (var fileStream = File.OpenRead(fileName))
            {
                using (var streamReader = new StreamReader(fileStream, 128))
                {
                    String line;
                    String current;
                    while ((line = streamReader.ReadLine()) != null)
                    {
                        if (float.TryParse(line, out price))
                        {
                            current = line;
                        }
                        else
                        {
                            if (!current.IsNullOrEmpty())
                                Console.WriteLine(current);
                            Console.WriteLine(line);
                        }
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            var fileName = "test.txt";
            HandleLatest(fileName);
        }
    }
}
