#include "lib.h"

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(min > arr[j]){
                minIndex = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}