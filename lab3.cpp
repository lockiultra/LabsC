#include <iostream>

int main()
{
    int countMin = 0, sum = 0, a = 0;
    const int n = 9;
    
    int arr[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "arr[" << i << ", " << j << "]:";
            std::cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) //поиск локальных минимумов
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] < arr[i][j + 1] && arr[i][j - 1] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i - 1][j])
            {
                countMin++;
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) //сумма модулей элементов выше главной диагонали
    {
        for (int j = 1 + a; j < n; j++)
        {
            sum += abs(arr[i][j]);
        }
        a++;
    }
    
    std::cout << "\nSum is " << sum << std::endl << std::endl << "Local minimums: " << countMin << std::endl;
    
    return EXIT_SUCCESS;
}