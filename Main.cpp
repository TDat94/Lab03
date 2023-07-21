#include "lib.h"

void checkAlgorithm(string algorithm, int a[], int n, int &comparison, double &time)
{
    if (algorithm=="selection_sort")
        selectionSort(a, n, comparison, time);
    else if (algorithm=="bubble_sort")
        measure_bubble_sort(a, n, time, comparison);
    else if (algorithm=="counting_sort")
        measure_counting_sort(a, n, time, comparison);
    else if (algorithm=="flash_sort")
        measure_flash_sort(a, n, time, comparison);
    else if (algorithm=="heap_sort")
        measure_heap_sort(a, n, time, comparison);
    else if (algorithm=="insertion_sort")
        measure_insertion_sort(a, n, time, comparison);
    else if (algorithm=="merge_sort")
        measureMergeSort(a, n, time, comparison);
    else if (algorithm=="quick_sort")
        measure_quickSort(a, n, comparison, time);
    else if (algorithm=="radix_sort")
        measure_radixSort(a, n, time, comparison);
    else if (algorithm=="shell_sort")
        shellSort(a, n, comparison, time);
    else if (algorithm=="shaker_sort")
        measure_shaker_sort(a, n, time, comparison);
    else
    {
        cerr << "This program is terminated due to invalid/unidentified algorithm.";
        terminate();
    }
}

void readCommand1(int argc, char *argv[], string &algorithm, string &filename, string &output_par)
{
    algorithm=argv[2];
    filename=argv[3];
    output_par=argv[4];
}

void executeCommand1(string algorithm, string filename, string output_par, int &comparison, double &time)
{
    ifstream ifs;
    ifs.open(filename);
    int n;
    ifs >> n;
    int a[n];
    for (int i=0; i<n; i++)
        ifs >> a[i];
    ifs.close();
    checkAlgorithm(algorithm, a, n, comparison, time);
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm:\n";
    cout << "Input file: " << filename << "\n";
    cout << "Input size: " << n << "\n";
    cout << "--------------------------------------\n";
    if (output_par=="-both")
    {
        cout << "Running time: " << time << "\n";
        cout << "Comparisons: " << comparison;
    }
    else if (output_par=="-time")
        cout << "Running time: " << time;
    else if (output_par=="-comp")
        cout << "Comparisons: " << comparison;
    ofstream ofs;
    ofs.open("output.txt");
    for (int i=0; i<n; i++)
        ofs << a[i] << " ";
    ofs << "\n";
    ofs.close();
}

int option(int argc, char *argv[])
{
    if (argc==4)
    {
        if (strcmp(argv[2], "-a")==0)
        {
            string temp=argv[3];
            int find=temp.find('.');
            if (find!=string::npos)
                return 1;
            else
                return 3;
        }
        else if (strcmp(argv[2], "-c")==0)
            return 4;
    }
    else if (argc==5)
    {
        if (strcmp(argv[2], "-a")==0)
            return 2;
        else if (strcmp(argv[2], "-c")==0)
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
    int Option=option(argc, argv);
    if (Option==0)
    {
        cout << "This program is terminated due to invalid/unidentified command prompt.";
        return 0;
    }
    if (Option==1)
    {
        readCommand1(argc,argv, algorithm, filename, output_par);
        executeCommand1(algorithm, filename, output_par, comparison, time);
    }
    else if (Option==2)
    {
        
    }
    else if (Option==3)
    {

    }
    else if (Option==4)
    {

    }
    else if (Option==5)
    {

    }
    return 0;
}