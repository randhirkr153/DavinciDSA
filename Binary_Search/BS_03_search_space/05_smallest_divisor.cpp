#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to calculate sum of ceilings
    // for a given divisor
    int findSum(vector<int>& arr, int divisor) {

        int sum = 0;

        for (int num : arr) {

            // Ceiling division
            sum += (num + divisor - 1) / divisor;
        }

        return sum;
    }

    // Intuition:
    // Divisor lies between 1 and max(arr).
    //
    // We apply Binary Search on divisor.
    //
    // If sum <= k:
    // try smaller divisor.
    //
    // Else:
    // increase divisor.
    //
    // Time Complexity:
    // O(n * log(max(arr)))
    //
    // Space Complexity:
    // O(1)

    int smallestDivisor(vector<int>& arr, int k) {

        int low = 1;

        int high = *max_element(arr.begin(), arr.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = findSum(arr, mid);

            if (sum <= k) {

                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int result = obj.smallestDivisor(arr, k);

    cout << "Smallest Divisor: " << result << endl;

    return 0;
}