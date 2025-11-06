#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int> &dist, vector<bool> &sptSet, int V) {
    int minVal = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    return minIndex;
}

void dijkstra(vector<vector<int>> &graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src);
    return 0;
}
