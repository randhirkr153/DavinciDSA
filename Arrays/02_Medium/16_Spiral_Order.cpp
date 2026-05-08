#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // Intuition:
        // Traverse matrix in spiral form:
        //
        // 1. Left to Right
        // 2. Top to Bottom
        // 3. Right to Left
        // 4. Bottom to Top
        //
        // Repeat for inner layers.

        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {

            // Left to Right
            for (int i = left; i <= right; i++) {

                ans.push_back(matrix[top][i]);
            }

            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++) {

                ans.push_back(matrix[i][right]);
            }

            right--;

            // Right to Left
            if (top <= bottom) {

                for (int i = right; i >= left; i--) {

                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            // Bottom to Top
            if (left <= right) {

                for (int i = bottom; i >= top; i--) {

                    ans.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return ans;
    }
};

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> matrix[i][j];
        }
    }

    Solution obj;

    vector<int> result = obj.spiralOrder(matrix);

    cout << "Spiral Order: ";

    for (int x : result) {

        cout << x << " ";
    }

    return 0;
}