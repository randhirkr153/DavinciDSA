#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int>& arr, int k) {

        // Intuition:
        // Binary Search works on sorted arrays.
        //
        // Find middle element:
        // - If middle == k → element found.
        // - If middle < k → search in right half.
        // - If middle > k → search in left half.
        //
        // Continue until element is found
        // or search space becomes empty.

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                return true;
            }

            else if (arr[mid] < k) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter element to search: ";
    cin >> k;

    Solution obj;

    if (obj.binarySearch(arr, k)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}