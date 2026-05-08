#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    int getOddOccurrence(vector<int>& arr) {

        /*
            Intuition:

            XOR has important properties:

            x ^ x = 0
            x ^ 0 = x

            Numbers occurring even times
            cancel each other.

            Only the odd occurring number remains.
        */

        int ans = 0;

        // XOR all elements
        for (int num : arr) {
            ans = ans ^ num;
        }

        return ans;
    }
};

int main() {

    int n;

    // Input size
    cin >> n;

    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    // Output
    cout << obj.getOddOccurrence(arr);

    return 0;
}