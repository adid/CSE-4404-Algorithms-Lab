#include <iostream>
using namespace std;
#include <chrono>
#include <iomanip>
 
// Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
    
    cout << endl;
}
 
// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

 
// Main Function
int main()
{
    // Sorting

    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    cout << "Sorted array through Bubble Sorting: \n";
    printArray(arr, size);

    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, size1);
    cout << "Sorted array through Insertion Sorting: \n";
    printArray(arr1, size1);
    
    // Time Findings

    int problemSizes[] = {100, 1000, 10000, 100000};
    int numSizes = sizeof(problemSizes) / sizeof(problemSizes[0]);

    for (int i = 0; i < numSizes; ++i) {
        int n = problemSizes[i];
        int* arr = new int[n];

        for (int i = 0; i < n; i++){
        arr[i] = rand() % n;
        }

        auto start = chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << fixed << setprecision(10);
        cout << "Bubble Sort execution time for n = " << n << ": " << duration.count() << " seconds." << endl;
    
        delete[] arr;
    }

    for (int i = 0; i < numSizes; ++i) {
        int n = problemSizes[i];
        int* arr = new int[n];

        for (int i = 0; i < n; i++){
        arr[i] = rand() % n;
        }

        auto start1 = chrono::high_resolution_clock::now();
        insertionSort(arr, n);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double> duration1 = end1 - start1;
        cout << fixed << setprecision(10);
        cout << "Insertion Sort execution time for n = " << n << ": " << duration1.count() << " seconds." << endl;

        delete[] arr;
    }

    return 0;

}

