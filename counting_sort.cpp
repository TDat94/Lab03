#include "lib.h"

int findMax_(int arr[], int n, long long &comparison)
{
    int Max=-1e9;
    for (int i=0; ++comparison && i<n; i++)
        if (++comparison && Max < arr[i])
            Max=arr[i];
    return Max;
}

int findMin(int arr[], int n, long long &comparison)
{
    int Min=1e9;
    for (int i=0; ++comparison && i<n; i++)
        if (++comparison && Min > arr[i])
            Min=arr[i];
    return Min;
}

void counting_sort(int arr[], int n, long long &comparison)
{
    comparison=0;
    int Max=findMax_(arr, n, comparison);
    int Min=findMin(arr, n, comparison);
    int *elements=new int[Max-Min+1];
    for (int i=0;++comparison && i<Max-Min+1; i++)
        elements[i]=0;
    for (int i=0;++comparison && i<n; i++)
        elements[arr[i]-Min]++;
    for (int i=1; ++comparison && i<Max-Min+1; i++)
        elements[i]=elements[i]+elements[i-1];
    int *newArray=new int[n];
    for (int i=n-1;++comparison && i>=0; i--)
    {
        newArray[elements[arr[i]-Min]-1]=arr[i];
        elements[arr[i]-Min]--;
    }
    for (int i=0;++comparison && i<n; i++)
        arr[i]=newArray[i];
    delete []elements;
    delete []newArray;
}

void measure_counting_sort(int arr[], int n, double &time, long long &comparison)
{
    clock_t start = clock();
    counting_sort(arr, n, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}