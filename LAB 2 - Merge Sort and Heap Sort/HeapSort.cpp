#include <iostream>
using namespace std;

void min_Heapify(int array[], int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] < array[smallest]) {
        smallest = left;
    }

    if (right < n && array[right] < array[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(array[i], array[smallest]);
        min_Heapify(array, smallest, n);
    }
}

void heap_Minimum(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_Heapify(array, i, n);
    }
}

void print_Heap(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << "\n";
}

int main() {
    int n, count = 0;
    cin >> n;
    int *arr = new int[n];

    for (int j = 0; j < n; j++) {
        int value;
        cin >> value;
        arr[j] = value;
    }

    cout << "Given array is \n";
    print_Heap(arr, n);

    heap_Minimum(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        min_Heapify(arr, 0, i);
    }

    cout << "\nSorted array is \n";
    print_Heap(arr, n);

    delete[] arr;
    return 0;
}
