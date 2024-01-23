#include <bits/stdc++.h>
using namespace std;

int n, c[10][10], visited[10];

void prim()
{
    int min, b, a, k, count = 0, cost = 0;
    min = 999;
    visited[1] = 1; /* 1st vertex is visited */
    while (count < n - 1) {
        min = 999;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (visited[i] && !visited[j] && min > c[i][j])
                {
                    min = c[i][j];
                    a = i;
                    b = j;
                }
        cout<<a<<" --> "<<b<<" = "<<c[a][b]<<endl;
        cost += c[a][b];
        visited[b] = 1;
        count++;
    }
    cout << "Total cost of spanning tree is " << cost;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix: "<< endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
        visited[i] = 0;
    }
    prim();
	return 0;
}
