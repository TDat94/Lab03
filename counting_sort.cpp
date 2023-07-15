#include "lib.h"

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

void measure_counting_sort(int arr[], int n, double &time, int &comparison)
{
    clock_t start = clock();
    counting_sort(arr, n, 1, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}