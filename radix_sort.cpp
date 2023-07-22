#include "lib.h"

// Function to find the maximum element in the array
int findMax(int arr[], int size, long long& comparison)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        comparison+=2;
        if (arr[i] > max)
            max = arr[i];
    }
    comparison++;
    return max;
}

void countingSort(int arr[], int size, int exp, long long&comparison)
{
    const int RADIX = 10; // The base of the radix system

    int output[size];
    int count[RADIX] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++)
    {
        comparison++; // Increment the comparison count for each iteration of the loop.
        count[(arr[i] / exp) % RADIX]++;
    }
    comparison++;

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < RADIX; i++)
    {
        comparison++; // Increment the comparison count for each iteration of the loop.
        count[i] += count[i - 1];
    }
    comparison++;

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        comparison++; // Increment the comparison count for each iteration of the loop.
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }
    comparison++;

    // Copy the output array to arr[] so that arr[] contains sorted numbers according to the current digit
    for (int i = 0; i < size; i++)
    {
        comparison++; // Increment the comparison count for each iteration of the loop.
        arr[i] = output[i];
    }
    comparison++;
}

void radixSort(int arr[], int size, long long&total_comparison)
{
    long long comparison = 0; // Local comparison count for each call of countingSort

    // Find the maximum number to know the number of digits
    int max = findMax(arr, size, comparison);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp, comparison);
        total_comparison += comparison; // Add the local comparison count to the total count.
    }
    total_comparison++;
}

void measure_radixSort(int arr[], int n, double &time, long long&comparison)
{
    clock_t start = clock();
    radixSort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}