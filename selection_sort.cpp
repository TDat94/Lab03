#include "lib.h"

void selection_sort(int arr[], int size, long long &comparison){
    for(int i = 0; ++comparison && i < size - 1; i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i + 1; ++comparison && j < size; j++){
            if(++comparison && min > arr[j]){
                minIndex = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void measure_selection_sort(int arr[], int size, long long &comparison, double &time){
    comparison = 0;
    clock_t start = clock();
    selection_sort(arr, size, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}
