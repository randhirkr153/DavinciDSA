#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findKRotation(vector<int> &arr) {

        int low = 0;
        int high = arr.size() - 1;

        /*
            Intuition:

            In a rotated sorted array:
            - One half is always sorted.
            - Minimum element lies in the unsorted half.

            The index of minimum element
            gives the number of rotations.
        */

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Minimum lies on right side
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }

            // Minimum lies at mid or left side
            else {
                high = mid;
            }
        }

        // low == index of minimum element
        return low;
    }
};

int main() {

    vector<int> arr = {5, 1, 2, 3, 4};

    Solution obj;

    cout << obj.findKRotation(arr);

    return 0;
}