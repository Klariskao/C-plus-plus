#include <iostream>
#define Out std::cout 

int main()
{
    Out << "i)\n\n";

    for (int i = 0; i < 45; i++)
    {
        i % 11 == 0 ? Out << "\n" : Out << "*";
    }
    Out << "------------------\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Out << "*";
        }

        Out << "\n";
    }

    Out << "------------------\n";

    Out << "**********\n";
    Out << "**********\n";
    Out << "**********\n";
    Out << "**********\n\n";

    Out << "ii)\n\n";

    for (int i = 1; i < 21; i++)
    {
        i == 2 || i == 5 || i == 9 || i == 14 || i == 20 || i == 21 ? Out << "\n" : Out << "*";
    }

    Out << "------------------\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            Out << "*";
        }

        Out << "\n";
    }

    Out << "------------------\n";

    Out << "*\n";
    Out << "**\n";
    Out << "***\n";
    Out << "****\n";
    Out << "*****\n\n";

    Out << "------------------\n";

    Out << "iii)\n\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 5; j++)
        {
            Out << " ";
        }
        for (int j = 0; j < i; j++)
        {
            Out << "*";
        }

        Out << "\n";
    }

    Out << "------------------\n";

    Out << "    *\n";
    Out << "   **\n";
    Out << "  ***\n";
    Out << " ****\n";
    Out << "*****\n\n";

    Out << "------------------\n";

    Out << "iv)\n\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 5; j++)
        {
            Out << " ";
        }
        for (int j = 0; j < (i * 2 - 1); j++)
        {
            Out << "*";
        }

        Out << "\n";
    }

    Out << "------------------\n";

    Out << "     *\n";
    Out << "    ***\n";
    Out << "   *****\n";
    Out << "  *******\n";
    Out << " *********\n";

    return 0;
}