#include <iostream>

std::string string = "Something to  print.";
int count = 1;
int countWords(std::string x)
{
    for (unsigned int i = 0; i < size(x); i++)
    {
        if (x[i] == ' ' && x[i + 1] != ' ') { count++; };
        if (x[i] == ' ' && x[i + 1] == ' ') 
            {
            std::cout << "More than one space in a row detected!\n";
            std::cout << "Please check your spelling.\n";
            }
    }
    return count;
}

int main()
{
    std::cout << countWords(string) << "\n";
    return 0;
}
