#include <bits/stdc++.h>
using namespace std;

int x[100];

int place(int k, int i) {
    for (int j = 1; j < k; j++) 
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}

void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++)
                        if (x[j] == p)
                            cout<<" Q ";
                        else
                            cout<<" * ";
                    cout<<endl;
                }
                cout<<endl;
            }
            else nqueen(k + 1, n);
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of queens: ";
    cin >> n;

    if (n==0 || n== 1 || n==2 || n==3)
        cout<<"\nThere is no solution for "<< n << " Queens problem", n;
    else if(n == 4)
        cout<<"Total number of solutions: 2"<<endl;

    auto start = chrono::high_resolution_clock::now();
    nqueen(1, n);
    auto end = chrono::high_resolution_clock::now();
        
    chrono::duration<double> duration = end - start;
    
    cout << endl<<"Time Complexity: " << duration.count() << " seconds" << endl;
    return 0;
}
