#include <iostream>
#include <stdlib.h>
#include <time.h>

#define n 5

void selsort(int *);
void bubsort(int *);
void insort(int *);

int linsearch(int *, int);
int binsearch(int *, int);

int main()
{
    srand(time(NULL));

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    //selsort(arr);
    //bubsort(arr);
    //insort(arr);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}

void selsort(int *arr)
{
    int curr = 0;
    int tmp = 0;

    for(int i = 0; i < n; i++)
    {
        curr = i;
        for(int j = i; j < n; j++)
        {
            if(arr[curr] > arr[j])
            {
                curr = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[curr];
        arr[curr] = tmp;
    }
}

void bubsort(int *arr)
{
    int tmp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void insort(int *arr)
{
    int key = 0;
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            arr[j + 1] = key;
        }
    }
}

int linsearch(int *arr, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

int binsearch(int *arr, int key)
{
    int mid = 0;
    bool searchComplit = false;

    int left = arr[0];
    int right = arr[n - 1];

    while(!searchComplit)
    {
        mid = (left + right) / 2;

        if (key < arr[mid])
        {
            right = mid - 1;
        }
        else if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
}
