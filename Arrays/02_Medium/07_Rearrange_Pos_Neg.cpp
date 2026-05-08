#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrange(vector<int>& arr) {

        // Intuition:
        // Store positive and negative numbers separately
        // while maintaining their order.
        //
        // Then alternatively place:
        // positive -> negative -> positive ...
        //
        // If one list gets exhausted,
        // add remaining elements as it is.

        vector<int> pos;
        vector<int> neg;

        // Separate positive and negative numbers
        for (int num : arr) {

            if (num >= 0) {
                pos.push_back(num);
            }
            else {
                neg.push_back(num);
            }
        }

        vector<int> ans;

        int i = 0;
        int j = 0;

        // Add alternately starting with positive
        while (i < pos.size() && j < neg.size()) {

            ans.push_back(pos[i]);
            i++;

            ans.push_back(neg[j]);
            j++;
        }

        // Remaining positive elements
        while (i < pos.size()) {

            ans.push_back(pos[i]);
            i++;
        }

        // Remaining negative elements
        while (j < neg.size()) {

            ans.push_back(neg[j]);
            j++;
        }

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

    vector<int> result = obj.rearrange(arr);

    cout << "Rearranged array: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}