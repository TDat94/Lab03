#include "lib.h"

void command2(string algorithm, int inputSize, string inputOrder, string outputParam){
    int arr[inputSize];
    if(inputOrder == "-rand"){
        GenerateData(arr, inputSize, 0);
    }
    else if(inputOrder == "-nsorted"){
        GenerateData(arr, inputSize, 3);
    }
    else if(inputOrder == "-sorted"){
        GenerateData(arr, inputSize, 1);
    }
    else if(inputOrder == "-rev"){
        GenerateData(arr, inputSize, 2);
    }
    else{
        GenerateData(arr, inputSize, -1);
    }
    double time = 0;
    int comparison = 0;
    if(algorithm == "selection-sort"){
        measure_selection_sort(arr, inputSize, comparison, time);
    }
    else if(algorithm == "insertion-sort"){
        measure_insertion_sort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "bubble-sort"){
        measure_bubble_sort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "merge-sort"){
        measure_merge_sort(arr, inputSize, comparison, time);
    }
    else if(algorithm == "quick-sort"){
        measure_quickSort(arr, inputSize, comparison, time);
    }
    else if(algorithm == "shell-sort"){
        measure_shell_sort(arr, inputSize, comparison, time);
    }
    else if(algorithm == "heap-sort"){
        measure_heap_sort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "flash-sort"){
        measure_flash_sort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "counting-sort"){
        measure_counting_sort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "radix-sort"){
        measure_radixSort(arr, inputSize, time, comparison);
    }
    else if(algorithm == "shaker-sort"){
        measure_shaker_sort(arr, inputSize, time, comparison);
    }
    else{
        cout << "Invalid algorithm!" << endl;
    }
    
    if(outputParam == "-time"){
        cout << "Running time: " << time << endl;
    }
    else if(outputParam == "-comp"){
        cout << "Comparisons: " << comparison << endl;
    }
    else if(outputParam == "-both"){
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
    }
}