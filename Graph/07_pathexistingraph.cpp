#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pathExist(int src, int dest, vector<vector<int>> &graph, vector<bool> &vis) {
        
        // If source equals destination
        if (src == dest) return true;

        vis[src] = true;

        for (int i = 0; i < graph[src].size(); i++) {
            int neighbor = graph[src][i];

            if (!vis[neighbor]) {
                if (pathExist(neighbor, dest, graph, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>> &edges, int src, int dest) {
        
        vector<vector<int>> graph(n);

        // Build adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            graph[v1].push_back(v2);
            graph[v2].push_back(v1); // undirected graph
        }

        vector<bool> vis(n, false);

        return pathExist(src, dest, graph, vis);
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    Solution obj;
    bool result = obj.validPath(n, edges, src, dest);

    if (result)
        cout << "Path exists\n";
    else
        cout << "No path exists\n";

    return 0;
}