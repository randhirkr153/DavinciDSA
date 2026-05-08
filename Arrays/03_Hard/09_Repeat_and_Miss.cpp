#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> findTwoElement(vector<int>& arr) {

        // Intuition:
        // Elements are from 1 to n.
        //
        // We use marking technique:
        //
        // For every number x:
        // visit index (x - 1)
        //
        // If value already negative:
        // x is repeating number
        //
        // Otherwise:
        // mark it negative
        //
        // After traversal,
        // the index having positive value
        // represents missing number.
        //
        // Time Complexity : O(n)
        // Space Complexity: O(1)

        int n = arr.size();

        int repeating = -1;
        int missing = -1;

        // Find repeating number
        for (int i = 0; i < n; i++) {

            int index = abs(arr[i]) - 1;

            // Already visited
            if (arr[index] < 0) {

                repeating = abs(arr[i]);
            }

            else {

                arr[index] = -arr[index];
            }
        }

        // Find missing number
        for (int i = 0; i < n; i++) {

            if (arr[i] > 0) {

                missing = i + 1;
                break;
            }
        }

        return {repeating, missing};
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

    vector<int> result =
        obj.findTwoElement(arr);

    cout << "\nRepeating Number = "
         << result[0] << endl;

    cout << "Missing Number = "
         << result[1] << endl;

    return 0;
}