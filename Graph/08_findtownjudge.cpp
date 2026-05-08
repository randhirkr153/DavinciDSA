#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Build indegree and outdegree
        for (int i = 0; i < trust.size(); i++) {
            int v1 = trust[i][0];
            int v2 = trust[i][1];

            outdegree[v1]++;
            indegree[v2]++;
        }

        // Find the judge
        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) {
                return i; // ✅ return correct person
            }
        }

        return -1;
    }
};

int main() {
    int n, t;
    cout << "Enter number of people and trust pairs: ";
    cin >> n >> t;

    vector<vector<int>> trust(t, vector<int>(2));

    cout << "Enter trust pairs (a b means a trusts b):\n";
    for (int i = 0; i < t; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }

    Solution obj;
    int judge = obj.findJudge(n, trust);

    if (judge == -1)
        cout << "No judge found\n";
    else
        cout << "Town Judge is: " << judge << endl;

    return 0;
}