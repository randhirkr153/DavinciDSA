#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {

        // Intuition:
        // Use Sliding Window technique.
        //
        // Expand window using right pointer.
        // Count number of zeros in current window.
        //
        // If zeros become greater than k,
        // shrink window from left side.
        //
        // Track maximum window length.

        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < arr.size(); right++) {

            if (arr[right] == 0) {
                zeroCount++;
            }

            // Shrink window if zeros exceed k
            while (zeroCount > k) {

                if (arr[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter binary array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Maximum consecutive 1's: "
         << obj.maxOnes(arr, k);

    return 0;
}