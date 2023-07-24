#include "lib.h"

void flash_sort(int arr[], int n, long long& totalcomp) {
    int max = 0, min = arr[0];
    int m = std::floor(0.45 * n);
    int* l = new int[m]();

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > arr[max]) {
            max = i;
        }
        totalcomp += 2;
    }
    totalcomp += n;

    if (min == arr[max]) {
        delete[] l; // Free the memory allocated for the array l
        return;
    }

    double c1 = (m - 1) / static_cast<double>(arr[max] - min);

    for (int j = 0; j < n; ++j) {
        int k = std::floor(c1 * (arr[j] - min));
        ++l[k];
    }
    totalcomp += n + 1;

    for (int p = 1; p < m; ++p) {
        l[p] = l[p] + l[p - 1];
    }
    totalcomp += n+1;

    int hold = arr[max];
    arr[max] = arr[0];
    arr[0] = hold;

    // Permutation
    int move = 0, t, flash;
    int j = 0;
    int k = m - 1;

    while (++totalcomp && move < (n - 1)) {
        while (++totalcomp && j > (l[k] - 1)) {
            ++j;
            k = std::floor(c1 * (arr[j] - min));
        }
        if (k < 0)
            break;
        flash = arr[j];
        while (++totalcomp && j != l[k]) {
            k = std::floor(c1 * (flash - min));
            hold = arr[t = --l[k]];
            arr[t] = flash;
            flash = hold;
            ++move;
        }
    }

    // Insertion
    for (j = 1; j < n; j++) {
        hold = arr[j];
        int i = j - 1;
        while ((++totalcomp && i >= 0) && (++totalcomp && arr[i] > hold)) {
            arr[i + 1] = arr[i--];
        }
        arr[i + 1] = hold;
    }
    totalcomp += n;

    delete[] l; // Free the memory allocated for the array l
}

void measure_flash_sort(int arr[], int n, double &time, long long &total_comp)
{
    clock_t start = clock();
    flash_sort(arr, n, total_comp);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}
