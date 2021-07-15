#include <iostream>

std::string lower = "abcdefghijklmnopqrstuvwxyz";
std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string toConvert = "something";

std::string converter(std::string x)
{
    for(unsigned int i = 0; i < size(x); i++)
        for (unsigned int j = 0; j < 27; j++)
            if (x[i] == lower[j])
            {
                x[i] = upper[j];
            }
    return x;
}

int main()
{
    std::cout << converter(toConvert) << "\n";

    return 0;
}