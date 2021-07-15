#include <iostream>

float r;


int main()
{
    std::cout << "Please enter the radius.\n";
    std::cin >> r;
    std::cout << "The area of circle with radius " << r << " equals " << r * r * 3.14159 << ".\n";
}