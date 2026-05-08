#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Intuition:
    // Each row is sorted in non-decreasing order.
    // So all 0s appear before 1s.
    //
    // We use Binary Search to find the first occurrence of 1
    // in every row.
    //
    // If first 1 is at index = idx
    // then number of 1s = m - idx
    //
    // We store:
    // 1. maximum number of 1s
    // 2. row index having maximum 1s
    //
    // Time Complexity: O(n * log m)

    int rowWithMax1s(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        int maxOnes = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {

            int low = 0;
            int high = m - 1;

            int firstOne = m;

            // Binary Search for first 1
            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (arr[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            int onesCount = m - firstOne;

            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {

    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    Solution obj;

    int result = obj.rowWithMax1s(arr);

    cout << "Row with maximum 1s: " << result << endl;

    return 0;
}