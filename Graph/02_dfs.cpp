#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int> &ans, vector<int> &vis, int node, vector<int> adj[]) {
        vis[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(ans, vis, it, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V, 0);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfs(ans, vis, i, adj);
            }
        }

        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    Solution obj;
    vector<int> result = obj.dfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }

    return 0;
}