#include "lib.h"

void merge(int arr[], int left, int right, int middle){
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for(int i = 0; i < leftSize; i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < rightSize; j++){
        rightArr[j] = arr[middle + j + 1];
    }
    int i = 0, j = 0, key = left;
    while(i < leftSize && j < rightSize){
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
    while(i < leftSize){
        arr[key] = leftArr[i];
        i++;
        key++;
    }
    while(j < rightSize){
        arr[key] = rightArr[j];
        j++;
        key++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, right, middle);
    }
}