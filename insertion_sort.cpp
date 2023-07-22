#include "lib.h"

void insertion_sort(int arr[], int n, long long& comparison) //source: geeks for geeks
{
    comparison = 0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while ((++comparison && j >= 0) && (++comparison && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    comparison += n; //count comparison in for loop
}

void measure_insertion_sort(int arr[], int n, double &time, long long &comparison)
{
    clock_t start = clock();
    insertion_sort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}