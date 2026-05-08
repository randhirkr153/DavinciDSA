#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool arraySortedOrNot(vector<int>& arr) {

        // Intuition:
        // Traverse the array from left to right.
        // If any element is smaller than the previous element,
        // then array is not sorted.
        // Otherwise array is sorted in non-decreasing order.

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }

        return true;
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

    if (obj.arraySortedOrNot(arr)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}