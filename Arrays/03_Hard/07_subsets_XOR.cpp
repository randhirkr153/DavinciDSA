#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int subsetXOR(vector<int>& arr, int K) {

        // Intuition:
        // We use Dynamic Programming.
        //
        // dp[i][x] =
        // Number of subsets using first i elements
        // having XOR value = x
        //
        // For every element:
        //
        // 1. Exclude current element
        // 2. Include current element
        //
        // XOR range:
        // Since arr[i] <= 100,
        // maximum XOR possible is < 128
        //
        // Time Complexity : O(N * 128)
        // Space Complexity: O(N * 128)

        int n = arr.size();

        int MAX_XOR = 128;

        vector<vector<int>> dp(n + 1,
                               vector<int>(MAX_XOR, 0));

        // Empty subset has XOR = 0
        dp[0][0] = 1;

        // Process elements one by one
        for (int i = 1; i <= n; i++) {

            for (int x = 0; x < MAX_XOR; x++) {

                // Exclude current element
                dp[i][x] += dp[i - 1][x];

                // Include current element
                dp[i][x] += dp[i - 1][x ^ arr[i - 1]];
            }
        }

        return dp[n][K];
    }
};

int main() {

    int N, K;

    cout << "Enter size of array: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Enter array elements: ";

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Enter K: ";
    cin >> K;

    Solution obj;

    int result = obj.subsetXOR(arr, K);

    cout << "Number of subsets with XOR "
         << K << " = " << result << endl;

    return 0;
}