#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

        // Intuition:
        // First sort intervals based on starting time.
        //
        // If current interval overlaps with
        // previous interval:
        //
        // current.start <= previous.end
        //
        // then merge them by updating end.
        //
        // Otherwise,
        // push new interval into answer.
        //
        // Time Complexity : O(n log n)
        // (for sorting)
        //
        // Space Complexity: O(n)

        int n = arr.size();

        // Sort intervals
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        // Add first interval
        ans.push_back(arr[0]);

        // Traverse remaining intervals
        for (int i = 1; i < n; i++) {

            int start = arr[i][0];
            int end = arr[i][1];

            // Last interval in answer
            int lastEnd = ans.back()[1];

            // Overlapping interval
            if (start <= lastEnd) {

                // Merge intervals
                ans.back()[1] =
                    max(lastEnd, end);
            }

            // Non-overlapping interval
            else {

                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    cout << "Enter intervals:\n";

    for (int i = 0; i < n; i++) {

        cin >> arr[i][0] >> arr[i][1];
    }

    Solution obj;

    vector<vector<int>> result =
        obj.mergeOverlap(arr);

    cout << "\nMerged Intervals:\n";

    for (auto interval : result) {

        cout << "[ "
             << interval[0]
             << " "
             << interval[1]
             << " ]\n";
    }

    return 0;
}