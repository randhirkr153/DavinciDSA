#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool search(vector<int>& arr, int key) {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Element found
            if (arr[mid] == key) {
                return true;
            }

            // Duplicates case
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
            }

            // Left half sorted
            else if (arr[low] <= arr[mid]) {

                // Key exists in left half
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                }

                // Search right half
                else {
                    low = mid + 1;
                }
            }

            // Right half sorted
            else {

                // Key exists in right half
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                }

                // Search left half
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {

    vector<int> arr = {3, 3, 3, 1, 2, 3};
    int key = 3;

    Solution obj;

    if (obj.search(arr, key))
        cout << "true";
    else
        cout << "false";

    return 0;
}