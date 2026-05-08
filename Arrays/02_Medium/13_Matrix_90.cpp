#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& mat) {

        // Intuition:
        // To rotate matrix by 90 degree anti-clockwise:
        //
        // Step 1:
        // Transpose the matrix
        // (swap mat[i][j] with mat[j][i])
        //
        // Step 2:
        // Reverse every column.
        //
        // This gives anti-clockwise rotation
        // without using extra space.

        int n = mat.size();

        // Step 1: Transpose matrix
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each column
        for (int j = 0; j < n; j++) {

            int top = 0;
            int bottom = n - 1;

            while (top < bottom) {

                swap(mat[top][j], mat[bottom][j]);

                top++;
                bottom--;
            }
        }
    }
};

int main() {

    int n;

    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> mat[i][j];
        }
    }

    Solution obj;

    obj.rotateMatrix(mat);

    cout << "Matrix after 90 degree anti-clockwise rotation:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << mat[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}