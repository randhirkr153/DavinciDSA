#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int maxProduct(vector<int>& arr) {

        // Intuition:
        // Negative number can turn
        // minimum product into maximum product.
        //
        // So at every index,
        // we maintain:
        //
        // maxEnding -> maximum product ending here
        // minEnding -> minimum product ending here
        //
        // Why minEnding?
        // Because:
        // negative * negative = positive
        //
        // If current element is negative,
        // swap maxEnding and minEnding.
        //
        // Time Complexity : O(n)
        // Space Complexity: O(1)

        int n = arr.size();

        int maxEnding = arr[0];
        int minEnding = arr[0];

        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            // If current element is negative
            // swap max and min
            if (arr[i] < 0) {

                swap(maxEnding, minEnding);
            }

            // Maximum product ending here
            maxEnding = max(arr[i],
                            maxEnding * arr[i]);

            // Minimum product ending here
            minEnding = min(arr[i],
                            minEnding * arr[i]);

            // Update answer
            ans = max(ans, maxEnding);
        }

        return ans;
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

    int result = obj.maxProduct(arr);

    cout << "\nMaximum Product Subarray = "
         << result << endl;

    return 0;
}