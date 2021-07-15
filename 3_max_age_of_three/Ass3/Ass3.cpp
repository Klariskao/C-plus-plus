#include <iostream>

unsigned int age1, age2, age3;

int main()
{
    std::cout << "Please enter three ages.\n";
    std::cin >> age1 >> age2 >> age3;
    if (age1 > age2 && age1 > age3)
    {
        std::cout << "Highest age is " << age1 << "\n";
    }
    else if (age2 > age3)
    {
        std::cout << "Highest age is " << age2 <<"\n";
    }
    else
    {
        std::cout << "Highest age is " << age3 << "\n";
    }
}