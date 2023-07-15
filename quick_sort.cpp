#include "lib.h"

int partition(int arr[], int low, int high, int& comparison)
{
    int pivot = arr[high];  // Pivot is the last element of the list
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        comparison++;  // Increment comparison count

        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int& total_comparison)
{
    if (low < high)
    {
        int comparison = 0;  // Initialize comparison count for each recursive call
        int pivotIndex = partition(arr, low, high, comparison);
        total_comparison += comparison;  // Add comparison count to the total

        quickSort(arr, low, pivotIndex - 1, total_comparison);
        quickSort(arr, pivotIndex + 1, high, total_comparison);
    }
}

void measure_quickSort(int arr[], int n, int& total_comparison, double& time)
{
    clock_t start = clock();
    quickSort(arr, 0, n - 1, total_comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}