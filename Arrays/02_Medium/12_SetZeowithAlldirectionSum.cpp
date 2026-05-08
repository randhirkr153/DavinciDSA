#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void MakeZeros(vector<vector<int>>& matrix) {

        // Intuition:
        // Operations must be performed according
        // to the INITIAL matrix.
        //
        // So first create a copy of matrix.
        //
        // Whenever matrix[i][j] == 0:
        // 1. Find sum of upper, lower,
        //    left and right elements
        //    from original matrix.
        // 2. Set adjacent cells to 0 in temp matrix.
        // 3. Put calculated sum at current zero position.

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {

                    int sum = 0;

                    // Upper
                    if (i - 1 >= 0) {
                        sum += matrix[i - 1][j];
                        temp[i - 1][j] = 0;
                    }

                    // Lower
                    if (i + 1 < n) {
                        sum += matrix[i + 1][j];
                        temp[i + 1][j] = 0;
                    }

                    // Left
                    if (j - 1 >= 0) {
                        sum += matrix[i][j - 1];
                        temp[i][j - 1] = 0;
                    }

                    // Right
                    if (j + 1 < m) {
                        sum += matrix[i][j + 1];
                        temp[i][j + 1] = 0;
                    }

                    // Put sum at zero position
                    temp[i][j] = sum;
                }
            }
        }

        matrix = temp;
    }
};

int main() {

    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> matrix[i][j];
        }
    }

    Solution obj;

    obj.MakeZeros(matrix);

    cout << "Modified Matrix:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}