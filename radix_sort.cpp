#include "lib.h"

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void counting_sort(int arr[], int n, int level, int &comparison)
{
    comparison=0;
    int *elements=new int[10]{0};
    int *newArray=new int[n];
    for (int i=0; comparison++ && i<n; i++)
        elements[(arr[i]/level)%10]++;
    for (int i=1; comparison++ && i<10; i++)
        elements[i]=elements[i]+elements[i-1];
    for (int i=n-1; comparison++ && i>=0; i--)
    {
        newArray[elements[(arr[i]/level)%10]-1]=arr[i];
        elements[(arr[i]/level)%10]--;
    }
    for (int i=0; comparison++ && i<n; i++)
        arr[i]=newArray[i];
    delete []newArray;
    delete []elements;
}

void radixSort(int arr[], int size, int total_comp)
{
    int comparison = 0;
    total_comp = 0;
    // Find the maximum number to know the number of digits
    int max = findMax(arr, size);

    // Perform counting sort for every digit
    for (int level = 1; total_comp++ && max / level > 0; level *= 10)
    {
        counting_sort(arr, size, level, comparison);
        total_comp += comparison;
    }
}

void measure_radixSort(int arr[], int n, double &time, int &comparison)
{
    clock_t start = clock();
    radixSort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}