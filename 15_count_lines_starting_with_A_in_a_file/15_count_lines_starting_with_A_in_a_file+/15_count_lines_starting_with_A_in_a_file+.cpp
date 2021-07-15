#include <iostream>
#include <fstream> 
#include <sstream>

int main()
{
    int count = 0;
    std::string item_name;
    std::ifstream nameFileout;
    nameFileout.open("out.txt");

    if (nameFileout.is_open())
    {
        while (std::getline(nameFileout, item_name))
        {
            if (item_name[0] != 'A')
            {
                count++;
            }

            std::cout << item_name << "\n";
        }

        std::cout << "\nNumber of lines not starting with an A is " << count << ".\n";
    }
    else
    {
        std::cout << "Reading error.\n";
    }
    nameFileout.close();
}