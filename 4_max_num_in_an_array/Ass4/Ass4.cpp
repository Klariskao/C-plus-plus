#include <iostream>

int numbers[] = {811, 21, 113, 41, 54, 3083};
int max = numbers[0];

int main()
{
   for (int i = 0; i < sizeof numbers / sizeof (int); i++)
    {
      if (numbers[i] < numbers[i+1] && numbers[i+1] > max)
      {
         max = numbers[i+1];
      }
   }
    std::cout << "Max number is " << max << "\n";
}