#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int>& arr) {

        // Intuition:
        // Since the array is already sorted,
        // duplicate elements will be adjacent.
        //
        // Start by storing the first element.
        // Traverse the array from index 1.
        // If current element is different from previous,
        // add it to answer vector.
        //
        // Finally return the vector containing unique elements.

        vector<int> ans;

        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] != arr[i - 1]) {
                ans.push_back(arr[i]);
            }
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

    vector<int> result = obj.removeDuplicates(arr);

    cout << "Array after removing duplicates: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}