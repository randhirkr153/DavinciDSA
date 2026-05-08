#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Intuition:
        // To rotate matrix by 90 degree clockwise:
        //
        // Step 1:
        // Transpose the matrix.
        //
        // Step 2:
        // Reverse every row.
        //
        // This performs rotation in-place
        // without using extra matrix.

        int n = matrix.size();

        // Step 1: Transpose matrix
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {

    int n;

    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> matrix[i][j];
        }
    }

    Solution obj;

    obj.rotate(matrix);

    cout << "Matrix after 90 degree clockwise rotation:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}