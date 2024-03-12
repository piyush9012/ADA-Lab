#include <bits/stdc++.h>
using namespace std;

void floyd(int a[][20], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] > (a[i][k] + a[k][j]))
                    a[i][j] = (a[i][k] + a[k][j]);
}

int main() {
    int n, a[20][20];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the cost adjacency matrix for the graph [999 for no edge, 0 for self loops]: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    floyd(a, n);
    cout << "All Pairs Shortest Paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
