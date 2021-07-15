#include <iostream>

int main()
{
    std::cout << "Please enter a number\n";
    int number;
    std::cin >> number;
    number %2 ? std::cout << "The number is odd\n" : std::cout << "The number is even\n";
}