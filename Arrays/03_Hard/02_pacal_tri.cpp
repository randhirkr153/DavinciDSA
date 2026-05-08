#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> generate(int numRows) {

        // Intuition:
        // Pascal Triangle rules:
        //
        // 1. First and last element of every row is 1
        // 2. Middle element =
        //    sum of two elements from previous row
        //
        // Example:
        //
        // Previous Row : 1 3 3 1
        // Current Row  : 1 4 6 4 1
        //
        // 4 = 1 + 3
        // 6 = 3 + 3
        // 4 = 3 + 1
        //
        // Time Complexity : O(n^2)
        // Space Complexity: O(n^2)

        vector<vector<int>> ans;

        // Generate rows one by one
        for (int i = 0; i < numRows; i++) {

            // Create row with all elements initially 1
            vector<int> row(i + 1, 1);

            // Fill middle elements
            for (int j = 1; j < i; j++) {

                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            // Store current row
            ans.push_back(row);
        }

        return ans;
    }
};

int main() {

    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution obj;

    vector<vector<int>> result = obj.generate(numRows);

    cout << "\nPascal Triangle:\n";

    for (auto row : result) {

        for (int val : row) {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}