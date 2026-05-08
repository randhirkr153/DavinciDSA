#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findAllPaths(vector<vector<int>> &graph, int currNode,
                      vector<bool> &visited, int n,
                      vector<int> &currPath,
                      vector<vector<int>> &res) {

        // If we reach target node (n-1)
        if (currNode == n - 1) {
            res.push_back(currPath);
            return;
        }

        if (visited[currNode]) return;

        // Mark current node as visited
        visited[currNode] = true;

        for (auto neighbour : graph[currNode]) {
            currPath.push_back(neighbour);
            findAllPaths(graph, neighbour, visited, n, currPath, res);
            currPath.pop_back(); // backtrack
        }

        // Unmark for other paths (backtracking)
        visited[currNode] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> res;
        vector<int> currPath;
        int n = graph.size();

        vector<bool> visited(n, false);

        // Start from node 0
        currPath.push_back(0);
        findAllPaths(graph, 0, visited, n, currPath, res);

        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter adjacency list:\n";
    for (int i = 0; i < n; i++) {
        int k;
        cout << "Number of neighbours of " << i << ": ";
        cin >> k;

        cout << "Enter neighbours: ";
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    Solution obj;
    vector<vector<int>> result = obj.allPathsSourceTarget(graph);

    cout << "\nAll paths from 0 to " << n - 1 << ":\n";
    for (auto path : result) {
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}