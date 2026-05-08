#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {

        int n = arr.size();

        // Intuition:
        // Rotate the array left by d positions.
        //
        // Store first d elements in temporary array.
        // Shift remaining elements to the left.
        // Place stored elements at the end.

        vector<int> temp;

        // Store first d elements
        for (int i = 0; i < d; i++) {
            temp.push_back(arr[i]);
        }

        // Shift remaining elements
        for (int i = d; i < n; i++) {
            arr[i - d] = arr[i];
        }

        // Put stored elements at end
        for (int i = 0; i < d; i++) {
            arr[n - d + i] = temp[i];
        }
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;

    cout << "Enter d: ";
    cin >> d;

    Solution obj;

    obj.rotateArr(arr, d);

    cout << "Array after rotation: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}