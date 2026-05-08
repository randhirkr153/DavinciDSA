#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {

        // Intuition:
        // Traverse array from right side.
        //
        // Keep track of maximum element seen so far.
        //
        // If current element is greater than or equal
        // to maximum, then it is a leader.
        //
        // Store leaders and finally reverse
        // because we traversed from right to left.

        vector<int> ans;

        int maxi = arr[arr.size() - 1];

        ans.push_back(maxi);

        for (int i = arr.size() - 2; i >= 0; i--) {

            if (arr[i] >= maxi) {

                maxi = arr[i];

                ans.push_back(arr[i]);
            }
        }

        reverse(ans.begin(), ans.end());

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

    vector<int> result = obj.leaders(arr);

    cout << "Leaders in array: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}