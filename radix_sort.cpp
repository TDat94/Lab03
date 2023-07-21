#include "lib.h"

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int size, int exp, int &comparison)
{
    const int RADIX = 10; // The base of the radix system

    int output[size];
    int count[RADIX] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; comparison++ && i < size; i++)
        count[(arr[i] / exp) % RADIX]++;

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; comparison++ && i < RADIX; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; comparison++ && i >= 0; i--)
    {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    // Copy the output array to arr[] so that arr[] contains sorted numbers according to the current digit
    for (int i = 0; comparison++ && i < size; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int size, int &total_comparison)
{
    int comparison = 0; // Local comparison count for each call of countingSort

    // Find the maximum number to know the number of digits
    int max = findMax(arr, size);

    // Perform counting sort for every digit
    for (int exp = 1; comparison++ && max / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp, comparison);
        total_comparison += comparison; // Add the local comparison count to the total count.
    }
}

void measure_radixSort(int arr[], int n, double &time, int &comparison)
{
    clock_t start = clock();
    radixSort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}