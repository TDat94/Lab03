#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#pragma once

using namespace std;

// Data generation
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

// Merge Sort
void merge(int arr[], int left, int right, int middle, int &comparison);
void mergeSort(int arr[], int left, int right, int &comparison);
void measureMergeSort(int arr[], int size, double &time, int &comparison);

// Shell Sort

// Selection Sort

// Counting Sort
void counting_sort(int arr[], int n, int level, int &comparison);
void measure_counting_sort(int arr[], int n, double &time, int &comparison);

// Radix Sort
int findMax(int arr[], int size);
void radixSort(int arr[], int size, int total_comp);
void measure_radixSort(int arr[], int n, double &time, int &comparison);

// Quick Sort
int partition(int arr[], int low, int high, int& comparison);
void quickSort(int arr[], int low, int high, int& total_comparison);
void measure_quickSort(int arr[], int n, int& total_comparison, double& time);

// Bubble Sort
void bubble_sort(int arr[], int n, int &comparison);
void measure_bubble_sort(int arr[], int n, double &time, int &comparison);

// Shaker Sort
void shaker_sort(int arr[], int n, int &comparison);
void measure_shaker_sort(int arr[], int n, double &time, int &comparison);