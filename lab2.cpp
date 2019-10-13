#include <iostream>

int *sort(int *arr, int n);
int input(int i);

int main()
{
    int *arr;
    int n, sum = 0, min = 10000;
    bool isNull = false;

    n = input(-1);

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = input(i);

        if (abs(arr[i]) < min)
        {
            min = arr[i];
        }

        if (isNull)
        {
            sum += abs(arr[i]);
        }

        if (arr[i] == 0)
        {
            isNull = true;
        }
    }

    std::cout << "\nMin is " << min << std::endl << std::endl;

    if (!isNull)
    {
        std::cout << "There aren't nulls" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Sum is " << sum << std::endl << std::endl;
    }

    int *arr2 = sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr2[i] << std::endl;
    }
    return EXIT_SUCCESS;
}

int *sort(int *arr, int n)
{
    int *tmpArr = (int*)malloc(sizeof(int));
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            tmpArr[a] = arr[i];
            a++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0 && i != 0)
        {
            tmpArr[a] = arr[i];
            a++;
        }
    }

    return tmpArr;
}

int input(int i)
{
    int num;
    bool inputCorrect = false;

    while(!inputCorrect)
    {
        if (i != -1)
        {
            std::cout << "Input arr[" << i << "]:";
        }
        else
        {
            std::cout << "Input size of array:";
        }
        try
        {
            std::cin >> num;

            if (!std::cin)
            {
                throw 1;
            }
            else
            {
                inputCorrect = true;
            }
        }
        catch(...)
        {
            std::cout << "Incorrect!\n";
        }
    }

    return num;
}
