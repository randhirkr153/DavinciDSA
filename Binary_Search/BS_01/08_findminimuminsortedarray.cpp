#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;

        /*
            Intuition:

            In a rotated sorted array:
            - One half is always sorted.
            - Minimum element always lies in the unsorted half.

            Example:
            [5, 6, 1, 2, 3, 4]

            mid = 1

            Left part  -> [5, 6]   (sorted)
            Right part -> [1, 2, 3, 4]

            Since left is sorted,
            minimum must be on right side.

            We keep reducing the search space
            using binary search.
        */

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Right half contains minimum
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }

            // Minimum is at mid or left half
            else {
                high = mid;
            }
        }

        // low == high -> minimum element index
        return arr[low];
    }
};

int main() {

    vector<int> arr = {5, 6, 1, 2, 3, 4};

    Solution obj;

    cout << obj.findMin(arr);

    return 0;
}