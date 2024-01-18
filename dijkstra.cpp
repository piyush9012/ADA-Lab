/* This program implements Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph. It uses a set to keep track of vertices with the minimum distance from the source and updates the distances as it explores the graph. */

#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <chrono> // Add this line

using namespace std;

const int INF = numeric_limits<int>::max();
void dijkstra(vector<vector<int>> &graph, int source, vector<int> &distance)
{
    int n = graph.size();
    distance.assign(n, INF);
    distance[source] = 0;

    set<pair<int, int>> s = {{0, source}};

    while (!s.empty())
    {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v])
            {
                s.erase({distance[v], v});
                distance[v] = distance[u] + graph[u][v];
                s.insert({distance[v], v});
            }
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> graph = {{INF, 2, 4, INF, INF},
                                 {INF, INF, 1, 7, INF},
                                 {INF, INF, INF, INF, 3},
                                 {INF, INF, INF, INF, 1},
                                 {INF, INF, INF, INF, INF}};

    int source = 1;
    vector<int> distance;

    auto start = chrono::high_resolution_clock::now();
    dijkstra(graph, source, distance);
    auto end = chrono::high_resolution_clock::now();

    cout << "Shortest distances from city " << source << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "City " << i << ": " << (distance[i] == INF ? "Not reachable" : to_string(distance[i]) + " units") << "\n";

    chrono::duration<double> duration = end - start;
    cout << "Time Complexity: " << duration.count() << " seconds" << endl;
    return 0;
}