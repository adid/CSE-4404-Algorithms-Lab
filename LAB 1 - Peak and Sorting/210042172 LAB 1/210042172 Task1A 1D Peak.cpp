#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
const int MAX = 256;

// peak element for 1D array

// Linear Peak

int findLinearPeak(int arr[], int n)
{
    if (n == 1)
        return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;
 

    for (int i = 1; i < n - 1; i++) 
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
}

// Binary Peak

int findBinaryPeak(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
 
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findBinaryPeak(arr, low, (mid - 1), n);
 
    else
        return findBinaryPeak(arr, (mid + 1), high, n);
}


// Main Function for 1D Peak

int main()
{
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Linear Peak Element is " << arr[findLinearPeak(arr, n)] << endl;
    cout << "Binary Peak Element is " << arr[findBinaryPeak(arr, 0, n-1, n)] << endl;


    int problemSizes[] = {1000,10000, 100000, 1000000, 10000000};
    int numSizes = sizeof(problemSizes) / sizeof(problemSizes[0]);

    for (int l = 0; l < numSizes; ++l) {
        int n = problemSizes[l];
        int* arr = new int[n];

        for (int i = 0; i < n; i++){
        arr[i] = rand() % n;
        }

        auto start = chrono::high_resolution_clock::now();
        findLinearPeak(arr, n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> durationMicroseconds = end - start;
        cout << fixed << setprecision(2);
        cout << "Linear Peak execution time for n = " << n << ": " << durationMicroseconds.count() << " microseconds." << endl;

        auto start1 = chrono::high_resolution_clock::now();
        findBinaryPeak(arr,0,n-1, n);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> durationMicroseconds1 = end1 - start1;
        cout << fixed << setprecision(2);
        cout << "Binary Peak execution time for n = " << n << ": " << durationMicroseconds1.count() << " microseconds." << endl;
        delete[] arr;
    }

    return 0;
}


//Execution Time

int executionTime()
{
    auto start = std::chrono::high_resolution_clock::now();

    

    // End the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    return 0;
}