#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution {
private:
    static void merge(int arr[], int low, int mid, int high) {
        vector<int> temp;      // temporary array
        int left = low;        // starting index of the left half of arr
        int right = mid + 1;   // starting index of the right half of arr

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

public:
    static void mergeSort(int arr[], int low, int high) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);      // left half
        mergeSort(arr, mid + 1, high); // right half
        merge(arr, low, mid, high);    // merging sorted halves
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    Solution::mergeSort(arr, 0, n - 1);

    cout << "\n\nAfter sorting array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    auto end = chrono::high_resolution_clock::now();
    auto executeTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "\n\nMerge sort takes: " << executeTime << "ms" << endl;

    return 0;
}