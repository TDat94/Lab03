#include "lib.h"

// void insertion_sort(int arr[], int n, int& comparison) //source: geeks for geeks
// {
//     comparison = 0;
//     int i, key, j;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;

//         // Move elements of arr[0..i-1],
//         // that are greater than key,
//         // to one position ahead of their
//         // current position
//         while ((++comparison && j >= 0) && (++comparison && arr[j] > key)) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
//     comparison += n; //count comparison in for loop
// }

void flash_sort(int a[], int n, long long& total_comp)
{
    long long comparison_flash = 0;
    total_comp = 0;

    //Find max and min of array
    int max = 0;
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (++total_comp && a[i] < min)
            min = a[i];
        if (++total_comp && a[i] > max)
            max = a[i];
    }
    total_comp += n; //count comparison in for loop

    //if all of elements in array is similar
    if (++total_comp && max == min)
        return;
    
    //create a dynamic array I has m elements. m is a class calculated by floor(0,45*n)
    int m = floor(0.45*n);
    int *l = new int [m]();

    //count number of elements of all classes base on rule: a[j] will be in k = floor((m-1)*(a[j]-min)/(max-min))
    for (int j = 0; j < n; j++)
    {
        int k = floor((m - 1) * (a[j] - min) / (max - min));
        ++l[k];
    }
    total_comp += n + 1;

    //calculate the last position of class z based on: l[z] = l[z] + l[z+1]
    for (int z = 1; z < m; z++)
    {
        l[z] += l[z-1];
    }
    total_comp += m;

    //Permute
    int move = 0, i = 0;
    while (++total_comp && move < n - 1)
    {
        //k is the class position of a[i]
        int k = floor((m - 1) * (a[i] - min) / (max - min));
        //when i >= l[k] means that a[i] is on correct position, and increase i to check next element
        while (++total_comp && i >= l[k])
        {
            i++;
            k = floor((m - 1) * (a[i] - min) / (max - min));
        }
        int flash = a[i];

        while (++total_comp && i != l[k])
        {
            k = floor((m - 1) * (flash - min) / (max - min));
            --l[k];
            int hold = a[l[k]];
            a[l[k]] = flash;
            flash = hold;
            move++;
        }
    }
    insertion_sort(a, n, comparison_flash);
    total_comp += comparison_flash;
}

void measure_flash_sort(int arr[], int n, double &time, long long &total_comp)
{
    clock_t start = clock();
    flash_sort(arr, n, total_comp);
    clock_t end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
}
