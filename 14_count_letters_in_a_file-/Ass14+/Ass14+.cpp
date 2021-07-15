#include <iostream>
#include <fstream> 
#include <sstream>

int main()
{
    std::ifstream readfrom("out.txt");
    if (readfrom.is_open())
    {
        int lettersNo = 0;
        std::string input;
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXZ";
       
        while (readfrom >> input)
        {
            std::cout << input;

            for (unsigned int i = 0; i < size(input); i++)
            {
                for (unsigned int j = 0; j < size(alphabet); j++)
                {
                    if (input[i] == alphabet[j])
                    {
                        lettersNo++;
                    }
                }
            }
        }
  
        

        std::cout << "\nReading successful.\n";
        std::cout << "Letters detected: " << lettersNo << "\n";
    }
    else
    {
        std::cout << "Reading error.\n";
    }

    readfrom.close();
}