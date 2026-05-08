#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr) {

        // Intuition:
        // Use Kadane's Algorithm.
        //
        // Keep adding elements to current sum.
        //
        // If current sum becomes greater than maximum,
        // update maximum sum.
        //
        // If current sum becomes negative,
        // reset it to 0 because negative sum
        // will decrease future subarray sums.

        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {

            currentSum += arr[i];

            maxSum = max(maxSum, currentSum);

            // Reset if current sum becomes negative
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Maximum Subarray Sum: "
         << obj.maxSubarraySum(arr);

    return 0;
}