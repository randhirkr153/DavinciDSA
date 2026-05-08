#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        // Intuition:
        // Since array contains only positive numbers,
        // use Sliding Window technique.
        //
        // Expand window by moving right pointer
        // and keep adding elements to sum.
        //
        // If sum becomes greater than k,
        // shrink window from left side.
        //
        // Whenever sum == k,
        // update maximum length.

        int left = 0;
        int sum = 0;
        int maxLen = 0;

        for (int right = 0; right < arr.size(); right++) {

            sum += arr[right];

            // Shrink window if sum > k
            while (sum > k) {
                sum -= arr[left];
                left++;
            }

            // Check if sum equals k
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter positive array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter target sum k: ";
    cin >> k;

    Solution obj;

    cout << "Longest subarray length: "
         << obj.longestSubarray(arr, k);

    return 0;
}