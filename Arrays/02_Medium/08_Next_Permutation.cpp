#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {

        // Intuition:
        //
        // Step 1:
        // Find first index from right
        // where arr[i] < arr[i + 1].
        // This is called breakpoint.
        //
        // Step 2:
        // Find just greater element from right
        // and swap with arr[i].
        //
        // Step 3:
        // Reverse elements after index i
        // to get next smallest permutation.
        //
        // If no breakpoint exists,
        // reverse whole array.

        int n = arr.size();

        int index = -1;

        // Find breakpoint
        for (int i = n - 2; i >= 0; i--) {

            if (arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        // If no breakpoint
        if (index == -1) {

            reverse(arr.begin(), arr.end());
            return;
        }

        // Find just greater element
        for (int i = n - 1; i > index; i--) {

            if (arr[i] > arr[index]) {

                swap(arr[i], arr[index]);
                break;
            }
        }

        // Reverse remaining part
        reverse(arr.begin() + index + 1, arr.end());
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter permutation elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    obj.nextPermutation(arr);

    cout << "Next Permutation: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}