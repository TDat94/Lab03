#include "lib.h"
#include "DataGenerator.cpp"

void bubble_sort(int arr[], int n, int &comparison)
{
    comparison=0;
    for (int j = 0; ++comparison && j < n; j++)
    {
        bool check = false;
        for (int i = 0; ++comparison && i < n - 1; i++)
        {
            if (++comparison && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                check = true;
            }
        }
        if (++comparison && !check)
            break;
    }
}

void measure_bubble_sort(int arr[], int n, double &time, int &comparison)
{
    clock_t start = clock();
    bubble_sort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}