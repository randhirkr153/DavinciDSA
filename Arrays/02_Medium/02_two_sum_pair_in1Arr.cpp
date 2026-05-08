#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Intuition:
        // Use Hash Map to store elements and indices.
        //
        // For each element:
        // needed = target - current element
        //
        // If needed element already exists,
        // return both indices.
        //
        // Otherwise store current element in map.

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int needed = target - nums[i];

            // Check if pair exists
            if (mp.find(needed) != mp.end()) {

                return {mp[needed], i};
            }

            // Store current number and index
            mp[nums[i]] = i;
        }

        return {};
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

    int target;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices are: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}