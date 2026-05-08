#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V, 0);
        queue<int> q;

        // Start BFS from node 0
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (auto it : adj[curr]) {
                if (vis[it] == 0) {
                    vis[it] = 1;
                    q.push(it);
                }
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
        adj[v].push_back(u); // remove this line for directed graph
    }

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }

    return 0;
}