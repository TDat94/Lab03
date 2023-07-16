#include "lib.h"

void merge(int arr[], int left, int right, int middle, int &comparison){
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for(int i = 0; comparison++ && i < leftSize; ++comparison, i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < rightSize; ++comparison, j++){
        rightArr[j] = arr[middle + j + 1];
    }
    int i = 0, j = 0, key = left;
    while((comparison += 2, i < leftSize) && j < rightSize){
        if(leftArr[i] < rightArr[j]){
            arr[key] = leftArr[i];
            i++;
        }
        else{
            arr[key] = rightArr[j];
            j++;
        }
        key++;
    }
    while(++comparison, i < leftSize){
        arr[key] = leftArr[i];
        i++;
        key++;
    }
    while(++comparison, j < rightSize){
        arr[key] = rightArr[j];
        j++;
        key++;
    }
}

void mergeSort(int arr[], int left, int right, int &comparison){
    if((comparison++, left < right)){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle, comparison);
        mergeSort(arr, middle + 1, right, comparison);
        merge(arr, left, right, middle, comparison);
    }
}

void measureMergeSort(int arr[], int size, double &time, int &comparison){
    clock_t start = clock();
    mergeSort(arr, 0, size - 1, comparison);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}