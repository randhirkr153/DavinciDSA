#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Intuition:
    // A peak element is greater than its neighbours.
    //
    // We use Binary Search.
    //
    // If arr[mid] < arr[mid + 1]
    // then peak must exist on RIGHT side.
    //
    // Else peak exists on LEFT side including mid.
    //
    // Because:
    // - increasing slope -> move right
    // - decreasing slope -> move left
    //
    // Time Complexity: O(log n)
    // Space Complexity: O(1)

    int peakElement(vector<int>& arr) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    int peakIndex = obj.peakElement(arr);

    cout << "Peak Element Index: " << peakIndex << endl;
    cout << "Peak Element Value: " << arr[peakIndex] << endl;

    return 0;
}