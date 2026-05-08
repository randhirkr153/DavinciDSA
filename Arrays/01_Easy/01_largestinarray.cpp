#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largest(vector<int>& arr) {

        // Intuition:
        // Start with first element as maximum.
        // Traverse the array one by one.
        // If any element is greater than current maximum,
        // update the maximum.
        // At the end, maximum element will be the answer.

        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }

        return maxi;
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

    cout << "Largest element is: " << obj.largest(arr);

    return 0;
}