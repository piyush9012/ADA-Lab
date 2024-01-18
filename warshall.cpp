#include <iostream>
#include <vector>
using namespace std;

void transitiveClosure(vector<vector<int>> &graph) {
    int n = graph.size();

    // Initialize the transitive closure matrix
    vector<vector<int>> closure(n, vector<int>(n, 0));

    // Set initial values based on the input graph
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            closure[i][j] = graph[i][j];

    // Update the closure matrix using Warshall's algorithm
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << closure[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}};

    transitiveClosure(graph);
    return 0;
}