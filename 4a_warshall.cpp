#include <bits/stdc++.h>
using namespace std;

void warshall(int a[][20], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = (a[i][j] || a[i][k] && a[k][j]);
}

int main() {
    int n, a[20][20];
    cout << "Enter number of nodes in the graph: \n";
    cin >> n;
    cout << "Enter the adjacency matrix for the graph: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    warshall(a, n);
    cout << "\nThe path matrix is: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] <<"\t";
        cout << endl;
    }
    return 0;
}
