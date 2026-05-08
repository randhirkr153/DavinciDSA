#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Intuition:
    // Matrix rows are individually sorted.
    //
    // Instead of flattening and sorting the whole matrix,
    // we apply Binary Search on the VALUE RANGE.
    //
    // Steps:
    // 1. Find minimum element and maximum element in matrix.
    // 2. Apply Binary Search between min and max.
    // 3. For every mid value:
    //      count how many elements are <= mid
    //      using upper_bound in each row.
    //
    // If count <= desired position,
    // move right side.
    //
    // Else move left side.
    //
    // Desired median position:
    // (n * m) / 2
    //
    // Time Complexity:
    // O(32 * n * log m)
    //
    // Space Complexity:
    // O(1)

    int median(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        // Find minimum and maximum element
        for (int i = 0; i < n; i++) {

            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int desired = (n * m) / 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int count = 0;

            // Count elements <= mid
            for (int i = 0; i < n; i++) {

                count += upper_bound(mat[i].begin(),
                                     mat[i].end(),
                                     mid) - mat[i].begin();
            }

            if (count <= desired) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
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

    Solution obj;

    int ans = obj.median(mat);

    cout << "Median of matrix: " << ans << endl;

    return 0;
}