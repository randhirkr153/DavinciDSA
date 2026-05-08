#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        // Intuition:
        // Sort the array first.
        //
        // Fix one element nums[i]
        // and use two pointers:
        //
        // left  -> i + 1
        // right -> n - 1
        //
        // Find triplets such that:
        // nums[i] + nums[left] + nums[right] = 0
        //
        // If sum < 0:
        // move left forward
        //
        // If sum > 0:
        // move right backward
        //
        // Skip duplicates to avoid
        // repeated triplets.
        //
        // Time Complexity : O(n^2)
        // Space Complexity: O(1)
        // (excluding answer array)

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Found valid triplet
                if (sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                // Need bigger sum
                else if (sum < 0) {
                    left++;
                }

                // Need smaller sum
                else {
                    right--;
                }
            }
        }

        return ans;
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

    Solution obj;

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "\nTriplets are:\n";

    if (result.empty()) {
        cout << "No triplets found";
    }
    else {

        for (auto triplet : result) {

            cout << "[ ";

            for (int x : triplet) {
                cout << x << " ";
            }

            cout << "]\n";
        }
    }

    return 0;
}