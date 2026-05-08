#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Find First Occurrence
    int firstOccurrence(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                ans = mid;
                high = mid - 1; // move left
            }

            else if (arr[mid] < x) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    // Find Last Occurrence
    int lastOccurrence(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1; // move right
            }

            else if (arr[mid] < x) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> find(vector<int>& arr, int x) {

        int first = firstOccurrence(arr, x);
        int last = lastOccurrence(arr, x);

        return {first, last};
    }
};

int main() {

    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;

    Solution obj;

    vector<int> ans = obj.find(arr, x);

    cout << ans[0] << " " << ans[1];

    return 0;
}