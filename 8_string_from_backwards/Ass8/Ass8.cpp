#include <iostream>

 std::string original = "Hellooo";

    void flipping(std::string x)
    {
        for(int i = size(x)-1; i >= 0; i--)
        {
            std::cout << x[i];
        }
    }

int main()
{
  flipping(original);
}