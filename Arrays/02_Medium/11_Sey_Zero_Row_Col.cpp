#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // Intuition:
        // Use first row and first column
        // as markers.
        //
        // If any element is 0:
        // mark its row and column.
        //
        // Then update matrix using markers.
        //
        // col0 handles first column separately.

        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for (int i = 0; i < n; i++) {

            if (matrix[i][0] == 0) {
                col0 = 0;
            }

            for (int j = 1; j < m; j++) {

                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Set inner matrix elements
        for (int i = 1; i < n; i++) {

            for (int j = 1; j < m; j++) {

                if (matrix[i][0] == 0 ||
                    matrix[0][j] == 0) {

                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if (matrix[0][0] == 0) {

            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if (col0 == 0) {

            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
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

    obj.setZeroes(matrix);

    cout << "Matrix after setting zeroes:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}