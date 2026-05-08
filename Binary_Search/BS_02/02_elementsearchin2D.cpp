#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Intuition:
    // Matrix rows and columns are sorted.
    //
    // Start from TOP RIGHT corner.
    //
    // If current element == x -> found
    //
    // If current element > x
    // move LEFT because smaller elements are on left side.
    //
    // If current element < x
    // move DOWN because larger elements are below.
    //
    // This removes one row or one column in every step.
    //
    // Time Complexity: O(n + m)
    // Space Complexity: O(1)

    bool searchMatrix(vector<vector<int>>& mat, int x) {

        int n = mat.size();
        int m = mat[0].size();

        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0) {

            if (mat[row][col] == x) {
                return true;
            }

            else if (mat[row][col] > x) {
                col--;
            }

            else {
                row++;
            }
        }

        return false;
    }
};

int main() {

    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    Solution obj;

    bool ans = obj.searchMatrix(mat, x);

    if (ans)
        cout << "Element Found" << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}