#include <iostream>

int a, b;

int main()
{

        std::cout << "Please enter two numbers:\n";
        std::cin >> a >> b;
#if 0
        a += b;
        b = a - b;
        a += - b;
        std::cout << "After swapping the numbers are: "<< a << " " << b << "\n";
#endif
        int c = a;
        a = b;
        b = c;
       
        std::cout << "After swapping the numbers are: " << a << " " << b << "\n";
}