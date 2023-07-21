#include "lib.h"

void shell_sort(int arr[], int size, int &comparison){
    //Split array into sub-arrays using intervals
    for(int interval = size / 2; interval >= 1; interval /= 2, ++comparison){
        //Insertion sort
        for(int i = interval; i < size; i++, ++comparison){ 
        //Check from the interval to the end of array, that means
        //first loop would be from 4 if size is 9
        //second loop from 2
        //third loop from 1, at third loop, it will be insertion sort
        // => do an insertion sort with sub arrays.
            int temp = arr[i];
            int j = i - interval;
            while((comparison += 2, j >= 0) && arr[j] > temp){
                arr[j + interval] = arr[j];
                j = j - interval;
            }
            arr[j + interval] = temp; 
        }
    }
}

void measure_shell_sort(int arr[], int size, int &comparison, double &time){
    comparison = 0;
    clock_t start = clock();
    shell_sort(arr, size, comparison);
    clock_t end = clock();
    time = double(end-start) / CLOCKS_PER_SEC;
}