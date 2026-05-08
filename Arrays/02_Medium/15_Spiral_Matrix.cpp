#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthElement(vector<vector<int>>& mat, int k) {

        // Intuition:
        // Traverse matrix in spiral order:
        // left -> right
        // top -> bottom
        // right -> left
        // bottom -> top
        //
        // Count elements while traversing.
        // When count becomes k,
        // return that element.

        int n = mat.size();
        int m = mat[0].size();

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        int count = 0;

        while (top <= bottom && left <= right) {

            // Left to Right
            for (int i = left; i <= right; i++) {

                count++;

                if (count == k) {
                    return mat[top][i];
                }
            }

            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; i++) {

                count++;

                if (count == k) {
                    return mat[i][right];
                }
            }

            right--;

            // Right to Left
            if (top <= bottom) {

                for (int i = right; i >= left; i--) {

                    count++;

                    if (count == k) {
                        return mat[bottom][i];
                    }
                }

                bottom--;
            }

            // Bottom to Top
            if (left <= right) {

                for (int i = bottom; i >= top; i--) {

                    count++;

                    if (count == k) {
                        return mat[i][left];
                    }
                }

                left++;
            }
        }

        return -1;
    }
};

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> mat[i][j];
        }
    }

    int k;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Kth element in spiral order: "
         << obj.kthElement(mat, k);

    return 0;
}