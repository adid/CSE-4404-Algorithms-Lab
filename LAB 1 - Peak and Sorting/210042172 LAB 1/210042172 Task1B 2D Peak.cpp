#include <iostream>
using namespace std;
const int MAX = 5000;
#include <chrono>
#include <iomanip>

//Brute Force Approach
int find2DPeakElementBF(int **arr, int rows, int columns) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         if (i == 0 && j == 0) {
            if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j + 1]) {
               return arr[i][j];
            }
         }
         else if (i == 0 && j == columns - 1) {
            if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j - 1]) {
               return arr[i][j];
            }
         }
         else if (i == rows - 1 && j == 0) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i][j + 1]) {
               return arr[i][j];
            }
         }
         else if (i == rows - 1 && j == columns - 1) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i][j - 1]) {
               return arr[i][j];
            }
         }
         else if (i == 0) {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i + 1][j]) {
               return arr[i][j];
            }
         }
         else if (i == rows - 1) {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j]) {
               return arr[i][j];
            }
         }
         else if (j == 0) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j + 1]) {
               return arr[i][j];
            }
         }
         else if (j == columns - 1) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j - 1]) {
               return arr[i][j];
            }
         }
         else {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j]) {
               return arr[i][j];
            }
         }
      }
   }
   return -1;
}

//Divide and Conquer Approach
int findMaxMid(int **arr,int rows, int mid, int&max) {
   int maxIndex = 0;

   for (int i = 0; i < rows; i++) {    //find max element in the mid column
      if (max <arr[i][mid]) {
         max = arr[i][mid];
         maxIndex = i;
      }
   }
   return maxIndex;
}

int find2DPeakElementDC(int **arr,int rows, int columns, int mid) {
   int maxMid = 0;
   int maxMidIndex = findMaxMid(arr, rows, mid, maxMid);

   if (mid == 0 || mid == columns-1)    //for first and last column, the maxMid is maximum
      return maxMid;
   // If maxMid is also peak
   if (maxMid>= arr[maxMidIndex][mid-1] &&maxMid>= arr[maxMidIndex][mid+1])
      return maxMid;

   if (maxMid<arr[maxMidIndex][mid-1])     // If maxMid is less than its left element
      return find2DPeakElementDC(arr, rows, columns, mid - mid/2);
   return find2DPeakElementDC(arr, rows, columns, mid+mid/2);
}

//Greedy Approach
int recur(int **a,int i, int j, int n) {
    if (i > 0 && a[i - 1][j] > a[i][j]) return recur(a,i - 1, j,n);
    else if (i < n - 1 && a[i + 1][j] > a[i][j]) return recur(a,i + 1, j,n);
    else if (j > 0 && a[i][j - 1] > a[i][j]) return recur(a,i, j - 1,n);
    else if (j < n - 1 && a[i][j + 1] > a[i][j]) return recur(a,i, j + 1,n);
    else return a[i][j];
}

int find2DPeakElementGreedy(int **a, int rows, int columns) {
    
    return recur(a,0,0,rows);
}

int main() {
   int rows = 4, columns = 4;
    int** arr = new int*[rows];
    
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[columns];
    }

    // Initializing the array
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3; arr[0][3] = 4;
    arr[1][0] = 2; arr[1][1] = 3; arr[1][2] = 4; arr[1][3] = 5;
    arr[2][0] = 1; arr[2][1] = 3; arr[2][2] = 7; arr[2][3] = 5;
    arr[3][0] = 1; arr[3][1] = 2; arr[3][2] = 6; arr[3][3] = 6;

    int mid = rows / 2;

    cout << "Brute Force Peak Finding: " <<find2DPeakElementBF(arr, rows, columns) << endl;
    cout << "Divide and Conquer Peak Finding: " <<find2DPeakElementDC(arr, rows, columns, mid) << endl;
    cout << "Greedy Peak Finding: " <<find2DPeakElementGreedy(arr, rows, columns) << endl;
   
    for (int i = 0; i < rows; ++i) {
         delete[] arr[i];
    }
    delete[] arr;

    // Time Finding

   int problemSizes[] = {10, 100, 1000, 5000};
   int numSizes = sizeof(problemSizes) / sizeof(problemSizes[0]);

   for (int l = 0; l < numSizes; ++l) {
         int n = problemSizes[l];
         int **arr = new int *[n];
         for (int i = 0; i < n; i++)
         {
            arr[i] = new int[n];
         }

    cout << "For Value of "<< n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    int peakRow = find2DPeakElementBF(arr, n, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> timeTaken = end - start;

    cout << "Time taken for Brute Force: " << fixed << setprecision(2) << timeTaken.count() << " microseconds" << endl;

    auto start1 = chrono::high_resolution_clock::now();
    int peakRow1 = find2DPeakElementDC(arr, n, n, n/2);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> timeTaken1 = end1 - start1;

    cout << "Time taken for Divide and Conquer: " << fixed << setprecision(2) << timeTaken1.count() << " microseconds" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    int peakRow2 = find2DPeakElementGreedy(arr, n, n);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> timeTaken2 = end2 - start2;

    cout << "Time taken for Greedy: " << fixed << setprecision(2) << timeTaken2.count() << " microseconds" << endl;
   
   }

   return 0;
}

int executionTime()
{
    auto start = std::chrono::high_resolution_clock::now();

    // End the timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    
    return 0;
}