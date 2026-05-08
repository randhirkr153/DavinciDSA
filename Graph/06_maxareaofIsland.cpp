#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findArea(vector<vector<int>> &grid, int currRow, int currCol, int m, int n) {
        
        // Base condition
        if (currRow < 0 || currRow >= m || currCol < 0 || currCol >= n 
            || grid[currRow][currCol] == 0) {
            return 0;
        }

        // Mark visited
        grid[currRow][currCol] = 0;

        int count = 1;

        // Explore 4 directions
        count += findArea(grid, currRow - 1, currCol, m, n); // up
        count += findArea(grid, currRow + 1, currCol, m, n); // down
        count += findArea(grid, currRow, currCol - 1, m, n); // left
        count += findArea(grid, currRow, currCol + 1, m, n); // right

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, findArea(grid, i, j, m, n));
                }
            }
        }
        return ans;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid (0 for water, 1 for land):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.maxAreaOfIsland(grid);

    cout << "\nMaximum Area of Island: " << result << endl;

    return 0;
}