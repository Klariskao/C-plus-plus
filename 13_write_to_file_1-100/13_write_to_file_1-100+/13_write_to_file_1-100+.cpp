#include <iostream>
#include <fstream>

int main()
{
    std::ofstream tofile("notes.txt");

    if (tofile.is_open())
    {
        for (int i = 1; i < 101; i++)
        {
            tofile << i << std::endl;
        }

        std::cout << "Writing successful.\n";
    }
    else
    {
        std::cout << "Writing error.\n";
    }

    tofile.close();
}