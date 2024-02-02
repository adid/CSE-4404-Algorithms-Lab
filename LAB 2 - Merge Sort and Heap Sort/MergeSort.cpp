#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
void merge(int array[], int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
 
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
 
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }

        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) 
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
 

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
 
int main()
{
    int n, count=0;
    cin >> n;
    int *arr = new int[n];
    
    for (int j = 0; j < n; j++) 
    {
        int value;
        cin >> value;
        arr[j] = value;
    }
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    mergeSort(arr, 0, n - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, n);
    return 0;
}
 