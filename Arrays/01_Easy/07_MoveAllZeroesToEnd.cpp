#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {

        // Intuition:
        // Use one pointer 'j' to keep track
        // of position for next non-zero element.
        //
        // Traverse array:
        // If current element is non-zero,
        // swap it with arr[j] and increment j.
        //
        // This keeps all non-zero elements
        // in same relative order and moves
        // all zeros to the end.

        int j = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] != 0) {

                swap(arr[i], arr[j]);

                j++;
            }
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

    Solution obj;

    obj.pushZerosToEnd(arr);

    cout << "Array after moving zeros to end: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}