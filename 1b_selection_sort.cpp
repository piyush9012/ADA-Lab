#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0; i<n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before selection sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    selection_sort(arr, n);

    cout <<"\nAfter selection sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    auto execute = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "\nSelection sort takes: " << execute << " ms" << endl;
    return 0;
}
