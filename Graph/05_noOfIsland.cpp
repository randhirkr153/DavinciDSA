#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void countIsland(vector<vector<char>> &grid, int currRow, int currCol, int row, int col) {
        
        // Base condition (out of bounds OR water)
        if (currRow < 0 || currRow >= row || currCol < 0 || currCol >= col 
            || grid[currRow][currCol] == '0') {
            return;
        }

        // Mark as visited (sink the island)
        grid[currRow][currCol] = '0';

        // Explore 4 directions
        countIsland(grid, currRow - 1, currCol, row, col); // up
        countIsland(grid, currRow + 1, currCol, row, col); // down
        countIsland(grid, currRow, currCol - 1, row, col); // left
        countIsland(grid, currRow, currCol + 1, row, col); // right
    }

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;

        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == '1') {
                    ans++;
                    countIsland(grid, i, j, row, col);
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

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter grid (0 for water, 1 for land):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.numIslands(grid);

    cout << "\nNumber of Islands: " << result << endl;

    return 0;
}