#include "lib.h"

void shell_sort(int arr[], int size, long long &comparison){
    //Split array into sub-arrays using intervals
    for(int interval = size / 2; ++comparison && interval >= 1; interval /= 2){
        //Insertion sort
        for(int i = interval; ++comparison && i < size; i++){ 
        //Check from the interval to the end of array, that means
        //first loop would be from 4 if size is 9
        //second loop from 2
        //third loop from 1, at third loop, it will be insertion sort
        // => do an insertion sort with sub arrays.
            int temp = arr[i];
            int j = i - interval;
            while((++comparison && j >= 0) && (++comparison && arr[j] > temp)){
                arr[j + interval] = arr[j];
                j = j - interval;
            }
            arr[j + interval] = temp; 
        }
    }
}

void measure_shell_sort(int arr[], int size, long long &comparison, double &time){
    comparison = 0;
    clock_t start = clock();
    shell_sort(arr, size, comparison);
    clock_t end = clock();
    time = double(end-start) / CLOCKS_PER_SEC;
}
