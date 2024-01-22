#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;          // temporary array
    int left = low;            // starting index of left half of arr
    int right = mid + 1;       // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {     // if elements on the left half are still left
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {    //  if elements on the right half are still left
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i<=high; i++) { // transfering all elements from temporary to arr
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "  ;
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "  ;

    auto end = chrono::high_resolution_clock::now();
    auto executeTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "\nMerge sort takes: " << executeTime << " ms" << endl;
    return 0;
}
