#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> findMajority(vector<int>& arr) {

        // Intuition:
        // Using Boyer-Moore Voting Algorithm
        //
        // Important Observation:
        // There can be at most 2 elements
        // that appear more than n/3 times.
        //
        // So we maintain:
        // candidate1, count1
        // candidate2, count2
        //
        // First pass:
        // Find possible candidates
        //
        // Second pass:
        // Verify their actual frequency
        //
        // Time Complexity : O(n)
        // Space Complexity: O(1)

        int n = arr.size();

        int candidate1 = -1, candidate2 = -1;
        int count1 = 0, count2 = 0;

        // Step 1: Find possible candidates
        for (int num : arr) {

            if (num == candidate1) {
                count1++;
            }

            else if (num == candidate2) {
                count2++;
            }

            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }

            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }

            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for (int num : arr) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;
        }

        vector<int> ans;

        if (count1 > n / 3)
            ans.push_back(candidate1);

        if (count2 > n / 3)
            ans.push_back(candidate2);

        // Result should be sorted
        sort(ans.begin(), ans.end());

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

    vector<int> result = obj.findMajority(arr);

    cout << "Majority Elements: ";

    if (result.empty()) {
        cout << "No majority element";
    }
    else {

        for (int x : result) {
            cout << x << " ";
        }
    }

    cout << endl;

    return 0;
}