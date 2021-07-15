#include <iostream>

int input;
int years;
int months;

int main()
{
    std::cout << "Enter the number of days\n";
    std::cin >> input;

    years = input / 365;
    input = input - years * 365;
    months = input / 30;
    input = input - months * 30;

    std::cout << "Years: " << years << "\n";
    std::cout << "Months: " << months << "\n";
    std::cout << "Days: " << input << "\n";
}
