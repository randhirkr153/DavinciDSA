#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int singleElement(vector<int>& arr) {

        int n = arr.size();

        // If only one element
        if (n == 1)
            return arr[0];

        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            /*
                Intuition:

                Before the single element:
                first occurrence starts at even index.

                After the single element:
                first occurrence starts at odd index.

                We make mid even to compare pairs easily.
            */

            // Make mid even
            if (mid % 2 == 1) {
                mid--;
            }

            // Pair is valid
            if (arr[mid] == arr[mid + 1]) {

                // Single element lies on right side
                low = mid + 2;
            }

            else {

                // Single element lies on left side including mid
                high = mid;
            }
        }

        return arr[low];
    }
};

int main() {

    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65};

    Solution obj;

    cout << obj.singleElement(arr);

    return 0;
}