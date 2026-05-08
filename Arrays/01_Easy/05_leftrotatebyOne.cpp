#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void leftRotateByOne(vector<int>& arr) {

        // Intuition:
        // Store first element temporarily.
        // Shift every element one position left.
        // Put first element at last position.

        int first = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            arr[i - 1] = arr[i];
        }

        arr[arr.size() - 1] = first;
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

    Solution obj;

    obj.leftRotateByOne(arr);

    cout << "Array after left rotation by one place: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}