#include <iostream>
#include <iomanip>
#include <string.h>

void error(char *desc, double *num);
double input(char *desc);

int main()
{
    double a, b, c, xStart, xEnd, xDelta;

    //input("a", &a);
    a = input("a");
    b = input("b");
    c = input("c");

    xStart = input("Start x");
    xEnd = input("End x");
    xDelta = input("Delta x");

    std::cout << "=======================\n|     x    |    F     |\n=======================\n";

    for (double x = xStart; x <= xEnd; x += xDelta)
    {
        if (x < 3 && b != 0)
        {
            std::cout << std::fixed << std::setprecision(2) << "|   " << x << "   |   " << a*x*x - b * x + c << "   |\n";
        }
        else if (x > 3 && b == 0)
        {
            std::cout << std::fixed << std::setprecision(2) << "|   " << x << "   |   " << (x - a) / (x - c) << "   |\n";
        }
        else
        {
            std::cout << std::fixed << std::setprecision(2) << "|   " << x << "   |   " << x / c << "   |\n";
        }

        std::cout << "=======================\n";
    }

    system("pause");

    return EXIT_SUCCESS;
}

double xs = 0, rx = 0; // xs - сохранение значения X Start, rx - разница между X End и X Start

double input(char *desc)
{
    double num;
    bool inputCorrect = false;

    while(!inputCorrect)
    {
        std::cout << "Input " << desc << ":";
        try
        {
            std::cin >> num;

            if (!std::cin)
            {
                throw 1;
            }

            if (strcmp(desc, "End x") == 0)
            {
                if (num < xs)
                {
                    throw 1;
                }
                else
                {
                    rx = num - xs;
                }
            }

            if (strcmp(desc, "Delta x") == 0)
            {
                if (num > rx)
                {
                    throw 1;
                }
                else
                {
                    inputCorrect = true;
                }
            }
            else
            {
                inputCorrect = true;
            }
        }
        catch(...)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Incorrect!\n";
        }

        if (strcmp(desc, "Start x") == 0)
        {
            xs = num;
        }
    }
    return num;
}
