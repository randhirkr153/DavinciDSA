#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &rs, vector<int> adj[]) {
        vis[node] = 1;
        rs[node] = 1;

        for (auto it : adj[node]) {
            // If not visited → DFS
            if (!vis[it]) {
                if (dfs(it, vis, rs, adj))
                    return true;
            }
            // If visited and in recursion stack → cycle
            else if (rs[it] == 1) {
                return true;
            }
        }

        // Remove from recursion stack
        rs[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> rs(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, rs, adj))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    Solution obj;
    bool hasCycle = obj.isCyclic(V, adj);

    if (hasCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}