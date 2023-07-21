#include "lib.h"

void checkAlgorithm(string algorithm, int a[], int n, int &comparison, double &time)
{
    if (algorithm == "selection_sort")
        measure_selection_sort(a, n, comparison, time);
    else if (algorithm == "bubble_sort")
        measure_bubble_sort(a, n, time, comparison);
    else if (algorithm == "counting_sort")
        measure_counting_sort(a, n, time, comparison);
    else if (algorithm == "flash_sort")
        measure_flash_sort(a, n, time, comparison);
    else if (algorithm == "heap_sort")
        measure_heap_sort(a, n, time, comparison);
    else if (algorithm == "insertion_sort")
        measure_insertion_sort(a, n, time, comparison);
    else if (algorithm == "merge_sort")
        measure_merge_sort(a, n, comparison, time);
    else if (algorithm == "quick_sort")
        measure_quickSort(a, n, comparison, time);
    else if (algorithm == "radix_sort")
        measure_radixSort(a, n, time, comparison);
    else if (algorithm == "shell_sort")
        measure_shell_sort(a, n, comparison, time);
    else if (algorithm == "shaker_sort")
        measure_shaker_sort(a, n, time, comparison);
    else
    {
        cerr << "This program is terminated due to invalid/unidentified algorithm.";
        terminate();
    }
}

int checkOutputParam(string param)
{
    if (param == "-time")
    {
        return 1;
    }
    else if (param == "-comp")
    {
        return 2;
    }
    else if (param == "-both")
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void readCommand1(int argc, char *argv[], string &algorithm, string &filename, string &output_par)
{
    algorithm = argv[2];
    filename = argv[3];
    output_par = argv[4];
}

void executeCommand1(string algorithm, string filename, string output_par, int &comparison, double &time)
{
    ifstream ifs;
    ifs.open(filename);
    int n;
    ifs >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        ifs >> a[i];
    ifs.close();
    checkAlgorithm(algorithm, a, n, comparison, time);
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm:\n";
    cout << "Input file: " << filename << "\n";
    cout << "Input size: " << n << "\n";
    cout << "--------------------------------------\n";
    if (output_par == "-both")
    {
        cout << "Running time: " << time << "\n";
        cout << "Comparisons: " << comparison;
    }
    else if (output_par == "-time")
        cout << "Running time: " << time;
    else if (output_par == "-comp")
        cout << "Comparisons: " << comparison;
    ofstream ofs;
    ofs.open("output.txt");
    for (int i = 0; i < n; i++)
        ofs << a[i] << " ";
    ofs << "\n";
    ofs.close();
}

void command2(string algorithm, int inputSize, string inputOrder, string outputParam)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << inputSize << endl;
    cout << "Input order: " << inputOrder << endl;
    cout << "--------------------------------------\n";
    int arr[inputSize];
    if (inputOrder == "-rand")
    {
        GenerateData(arr, inputSize, 0);
    }
    else if (inputOrder == "-nsorted")
    {
        GenerateData(arr, inputSize, 3);
    }
    else if (inputOrder == "-sorted")
    {
        GenerateData(arr, inputSize, 1);
    }
    else if (inputOrder == "-rev")
    {
        GenerateData(arr, inputSize, 2);
    }
    else
    {
        GenerateData(arr, inputSize, -1);
    }
    double time = 0;
    int comparison = 0;

    checkAlgorithm(algorithm, arr, inputSize, comparison, time);
    int output = checkOutputParam(outputParam);
    switch (output)
    {
    case 0:
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisons: " << comparison << endl;
        break;
    case -1:
        cout << "Invalid parameter found!" << endl;
        break;
    }
}

void command3(string algorithm, int inputSize, string outputParam)
{
    int *arr = new int[inputSize];
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << inputSize << endl;
    cout << "--------------------------------------\n";
    cout << "Input order: Randomize" << endl;
    int comparison = 0;
    double time = 0;
    GenerateData(arr, inputSize, 0);
    checkAlgorithm(algorithm, arr, inputSize, comparison, time);
    int output = checkOutputParam(outputParam);
    switch (output)
    {
    case 0:
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisons: " << comparison << endl;
        break;
    case -1:
        cout << "Invalid parameter found!" << endl;
        break;
    }
    comparison = 0;
    time = 0;
    GenerateData(arr, inputSize, 1);
    checkAlgorithm(algorithm, arr, inputSize, comparison, time);
    switch (output)
    {
    case 0:
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisons: " << comparison << endl;
        break;
    case -1:
        cout << "Invalid parameter found!" << endl;
        break;
    }
    cout << "--------------------------------------\n";
    cout << "Input order: Reverse" << endl;
    comparison = 0;
    time = 0;
    GenerateData(arr, inputSize, 2);
    checkAlgorithm(algorithm, arr, inputSize, comparison, time);
    switch (output)
    {
    case 0:
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisons: " << comparison << endl;
        break;
    case -1:
        cout << "Invalid parameter found!" << endl;
        break;
    }
    cout << "--------------------------------------\n";
    cout << "Input order: Nearly Sorted" << endl;
    comparison = 0;
    time = 0;
    GenerateData(arr, inputSize, 3);
    checkAlgorithm(algorithm, arr, inputSize, comparison, time);
    switch (output)
    {
    case 0:
        cout << "Running time: " << time << endl;
        cout << "Comparisons: " << comparison << endl;
        break;
    case 1:
        cout << "Running time: " << time << endl;
        break;
    case 2:
        cout << "Comparisons: " << comparison << endl;
        break;
    case -1:
        cout << "Invalid parameter found!" << endl;
        break;
    }
}

int option(int argc, char *argv[])
{
    if (argc == 4)
    {
        if (strcmp(argv[2], "-a") == 0)
        {
            string temp = argv[3];
            int find = temp.find('.');
            if (find != string::npos)
                return 1;
            else
                return 3;
        }
        else if (strcmp(argv[2], "-c") == 0)
            return 4;
    }
    else if (argc == 5)
    {
        if (strcmp(argv[2], "-a") == 0)
            return 2;
        else if (strcmp(argv[2], "-c") == 0)
            return 5;
    }
    else
        return 0;
}

int main(int argc, char *argv[])
{
    string algorithm;
    string filename;
    string output_par;
    int comparison;
    double time;
    int Option = option(argc, argv);
    if (Option == 0)
    {
        cout << "This program is terminated due to invalid/unidentified command prompt.";
        return 0;
    }
    if (Option == 1)
    {
        readCommand1(argc, argv, algorithm, filename, output_par);
        executeCommand1(algorithm, filename, output_par, comparison, time);
    }
    else if (Option == 2)
    {
    }
    else if (Option == 3)
    {
    }
    else if (Option == 4)
    {
    }
    else if (Option == 5)
    {
    }
    return 0;
}