#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& arr, int key) {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Element found
            if (arr[mid] == key) {
                return mid;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid]) {

                // Key lies in left half
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                }

                // Search right half
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Key lies in right half
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                }

                // Search left half
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;

    Solution obj;

    cout << obj.search(arr, key);

    return 0;
}