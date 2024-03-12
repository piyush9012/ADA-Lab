#include <bits/stdc++.h>
using namespace std;

int cost[10][10], parent[10], a, b, n;

void find_min() {
    int min = 999;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (cost[i][j] < min) {
                min = cost[i][j];
                a = i;
                b = j;
            }
}

int check_cycle(int a, int b) {
    if ((parent[a] == parent[b]) && (parent[a] != 0))
        return 0;
    else if (parent[a] == 0 && parent[b] == 0)
        parent[a] = parent[b] = a;
    else if (parent[a] == 0)
        parent[a] = parent[b];
    else if (parent[a] != parent[b])
        parent[b] = parent[a];
    return 1;
}

int main() {
    int count = 0, sum = 0, flag = 0, min;
    cout<<"Enter the number of vertices: ";
    cin >> n;
    cout<<"Enter the cost matria (Enter 999 for No edges and self loop )\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
            parent[j] = 0;
        }
    while (count != n - 1 && min != 999) {
        find_min();
        flag = check_cycle(a, b);
        if (flag == 1) {
            count++;
            sum += cost[a][b];
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout<<"\nThe total cost of minimum spanning tree " << sum;
    return 0;
}