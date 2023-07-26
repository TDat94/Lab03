#include "lib.h"

int chooseMiddlePivot(int arr[], int low, int high)
{
    return low + (high - low) / 2;
}

int partition(int arr[], int low, int high, long long& comparison)
{
    int pivotIndex = chooseMiddlePivot(arr, low, high);
    int pivot = arr[pivotIndex];
    // Move the pivot to the end
    swap(arr[pivotIndex], arr[high]);
    int i = low - 1;

    for (int j = low; ++comparison && j <= high - 1; j++)
    {
        if (++comparison && arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, long long& total_comparison)
{
    if (++total_comparison && low < high) {
        long long comparison = 0; // Initialize comparison count for each recursive call
        int pivotIndex = partition(arr, low, high, comparison);
        total_comparison += comparison; // Add comparison count to the total

        quickSort(arr, low, pivotIndex - 1, total_comparison);
        quickSort(arr, pivotIndex + 1, high, total_comparison);
    }
    total_comparison++;
}

void measure_quickSort(int arr[], int n, long long& total_comparison, double& time)
{
    clock_t start = clock();
    quickSort(arr, 0, n - 1, total_comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}