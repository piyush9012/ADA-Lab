#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before Quick sort:"<<endl;
    printArr(arr, n);
    quickSort(arr, 0, n - 1);
    cout<<"\nAfter Quick sort:"<<endl;
    printArr(arr, n);

    auto end = chrono::high_resolution_clock::now();
    auto executionTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout<<"\nQuick Sort takes "<<executionTime<<" ms"<<endl;
    return 0;
}
