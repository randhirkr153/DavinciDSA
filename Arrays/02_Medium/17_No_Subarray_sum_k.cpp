#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Intuition:
        // Use Prefix Sum + Hash Map.
        //
        // If:
        // currentSum - k exists before,
        // then a subarray with sum k exists.
        //
        // Store frequency of prefix sums
        // in hash map.

        unordered_map<int, int> mp;

        // Base case
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            // Check if required prefix exists
            if (mp.find(sum - k) != mp.end()) {

                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {

        cin >> nums[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    cout << "Total subarrays with sum k: "
         << obj.subarraySum(nums, k);

    return 0;
}