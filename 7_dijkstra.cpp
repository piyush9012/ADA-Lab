#include <iostream>
using namespace std;

int main()
{
    int n, a[10][10], s[10], d[10], v, u, min;
    cout << "Enter the no. of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix (Enter 999 if no edge between vertices):" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << "Enter the source vertex: ";
    cin >> v;
    for (int i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = a[v][i];
    }
    d[v] = 0;
    s[v] = 1;
    for (int k = 2; k <= n; k++) {
        min = 999;
        for (int i = 1; i <= n; i++){
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        s[u] = 1;
        for (int i = 1; i <= n; i++){
            if (s[i] == 0) {
                if (d[i] > d[u] + a[u][i])
                    d[i] = d[u] + a[u][i];
            }
        }
    }

    cout << "The shortest distance from " << v <<":"<< endl;
    for (int i = 1; i <= n; i++)
        cout<<v<<" --> "<<i<<" = "<<d[i]<< endl;
    return 0;
}
