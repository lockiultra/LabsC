#include <iostream>
#include <iomanip>

void input(char *desc, double *num);
void error(char *desc, double *num);

int main()
{
    double a, b, c, xStart, xEnd, xDelta;

    input("a", &a);
    input("b", &b);
    input("c", &c);

    input("Start x", &xStart);
    input("End x", &xEnd);
    input("Delta x", &xDelta);

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
    return EXIT_SUCCESS;
}

double xs = 0, rx = 0; // xs - сохранение значения X Start, rx - разница между X End и X Start

void input(char *desc, double *num) // функция ввода данных с проверкой корректности
{
    std::cout << "Input " << desc << ":";
    std::cin >> *num;

    if (!std::cin)
    {
        error(desc, num);
    }

    if (strcmp(desc, "Start x") == 0)
    {
        xs = *num;
    }

    if (strcmp(desc, "End x") == 0)
    {
        if (*num < xs)
        {
            error(desc, num);
        }
        else
        {
            rx = *num - xs;
        }
    }

    if (strcmp(desc, "Delta x") == 0)
    {
        if (*num > rx)
        {
            error(desc, num);
        }
    }
}

void error(char *desc, double *num) // вывод об ошибке, очистка потока cin
{
    std::cout << "Incorrect number!\n";

    std::cin.clear();
    std::cin.ignore();

    input(desc, num);
}