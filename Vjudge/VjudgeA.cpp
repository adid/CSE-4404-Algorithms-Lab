#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long mergeSort(int arr[], int temp[], int left, int right);
long long merge(int arr[], int temp[], int left, int mid, int right);

long long _mergeSort(int arr[], int array_size) {
    int temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1);
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    long long count = 0;

    if (right > left) {
        mid = (right + left) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long count = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int main() {
    int t;
    cin >> t;
    cout << "\n";

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int *array = new int[n];
        for (int j = 0; j < n; j++) {
            int value;
            cin >> value;
            array[j] = value;
        }
        cout << "\n";
        cout << _mergeSort(array, n) << endl;
        delete[] array; // free the dynamically allocated array
    }

    return 0;
}
