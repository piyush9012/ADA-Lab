#include <bits/stdc++.h>
using namespace std;

int n, c[10][10], vis[10];

void prim() {
    int min, a, b, count = 0, cost = 0;
    vis[1] = 1;          /* 1st vertex is visited */
    while (count < n-1) {
        min = 999;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (vis[i] && !vis[j] && min > c[i][j]) /* if i is visited but j is not visited and c[i][j] < min*/
                {
                    min = c[i][j]; /* assign c[i][j] as minimum cost */
                    a = i;
                    b = j;
                }
        cout<<a<<" --> "<<b<<" = "<<c[a][b]<<endl; /* prints each edge in the MST and its cost */
        cost += c[a][b];         //   adds the minimum cost
        vis[b] = 1;
        count++;
    }
    cout << "Total cost of spanning tree is " << cost; /* cost holds the minimum cost of the MST */
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix: "<< endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
        vis[i] = 0;
    }
    auto start = chrono::high_resolution_clock::now();
    prim();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << endl<<"Time Complexity: " << duration.count() << " seconds" << endl;
	return 0;
}
