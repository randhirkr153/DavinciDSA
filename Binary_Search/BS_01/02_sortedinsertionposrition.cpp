#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
        
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Element found
            if (arr[mid] == k) {
                return mid;
            }

            // Search right half
            else if (arr[mid] < k) {
                low = mid + 1;
            }

            // Search left half
            else {
                high = mid - 1;
            }
        }

        // Position where element should be inserted
        return low;
    }
};

int main() {

    vector<int> arr = {1, 3, 5, 6};
    int k = 2;

    Solution obj;

    cout << obj.searchInsert(arr, k);

    return 0;
}