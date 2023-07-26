#include "lib.h"

void heapify(int arr[], int N, int i, long long& comparison) //source: geeks for geeks
{
    comparison = 0;
    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if ((++comparison && l < N) && (++comparison && arr[l] > arr[largest]))
        largest = l;

    // If right child is larger than largest
    // so far
    if ((++comparison && r < N) && (++comparison && arr[r] > arr[largest]))
        largest = r;

    // If largest is not root
    if (++comparison && largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest, comparison);
    }
}

void heap_sort(int arr[], int N, long long & total_comp)
{
    long long comparison_heap = 0;
    total_comp = 0;
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; ++total_comp && i >= 0; i--)
    {
        heapify(arr, N, i, comparison_heap);
        total_comp += comparison_heap;
    }

    // One by one extract an element
    // from heap
    for (int i = N - 1; ++total_comp && i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, comparison_heap);
        total_comp += comparison_heap;
    }
}

void measure_heap_sort(int arr[], int n, double &time, long long &total_comp)
{
    clock_t start = clock();
    heap_sort(arr, n, total_comp);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}
