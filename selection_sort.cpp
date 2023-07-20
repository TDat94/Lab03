#include "lib.h"

void selectionSort(int arr[], int size, int &comparison, double &time){
    clock_t start = clock();
    for(int i = 0; i < size - 1; ++comparison, i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i + 1; j < size; ++comparison, j++){
            if(++comparison, min > arr[j]){
                minIndex = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}