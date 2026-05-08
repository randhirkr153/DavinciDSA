#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        // Intuition:
        // Use Prefix Sum + Hash Map.
        //
        // Store first occurrence of each prefix sum.
        //
        // If:
        // currentSum - k exists in map,
        // then subarray with sum k exists.
        //
        // Length =
        // current index - index of (currentSum - k)
        //
        // Update maximum length.

        unordered_map<int, int> mp;

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            // If sum itself equals k
            if (sum == k) {
                maxLen = i + 1;
            }

            // Check if remaining sum exists
            if (mp.find(sum - k) != mp.end()) {

                int len = i - mp[sum - k];

                maxLen = max(maxLen, len);
            }

            // Store first occurrence only
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
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

    cout << "Enter array elements: ";
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