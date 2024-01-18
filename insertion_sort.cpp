#include <iostream>
#include <chrono>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n-1; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    cout << "\n\nAfter Insertion sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    insertion_sort(arr, n);

    auto end = chrono::high_resolution_clock::now();
    auto executeTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "\n\nInsertion sort takes: " << executeTime << "ms" << endl;

    return 0;
}
