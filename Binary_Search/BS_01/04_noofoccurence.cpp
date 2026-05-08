#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // First Occurrence
    int firstOccurrence(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1; // move left
            }

            else if (arr[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    // Last Occurrence
    int lastOccurrence(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1; // move right
            }

            else if (arr[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countFreq(vector<int>& arr, int target) {

        int first = firstOccurrence(arr, target);

        // Element not found
        if (first == -1)
            return 0;

        int last = lastOccurrence(arr, target);

        return last - first + 1;
    }
};

int main() {

    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;

    Solution obj;

    cout << obj.countFreq(arr, target);

    return 0;
}