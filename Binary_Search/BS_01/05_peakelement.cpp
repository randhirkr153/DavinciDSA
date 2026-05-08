#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int peakElement(vector<int> &arr) {

        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Peak is on right side
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }

            // Peak is on left side or at mid
            else {
                high = mid;
            }
        }

        return low; // or high
    }
};

int main() {

    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};

    Solution obj;

    int index = obj.peakElement(arr);

    cout << "Peak Index = " << index << endl;
    cout << "Peak Element = " << arr[index];

    return 0;
}