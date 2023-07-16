#include "lib.h"

void shaker_sort(int arr[], int n, int &comparison)
{
    int comparison=0;
    int left = 0;
    int right = n - 1;
    while (comparison++ && true)
    {
        bool check = false;
        for (int i = left; comparison++ && i < right; i++)
        {
            if (comparison++ && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                check = true;
            }
        }
        right--;
        if (!check)
            break;
        for (int i = right; comparison++ && i > left; i--)
        {
            if (comparison++ && arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        left++;
    }
}

void measure_shaker_sort(int arr[], int n, double &time, int &comparison)
{
    clock_t start = clock();
    shaker_sort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}