#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    vector<int> twoOddNum(vector<int>& arr) {

        /*
            Intuition:

            All even occurring numbers cancel out using XOR.

            After XOR of all elements:

            xorValue = x ^ y

            where x and y are the two odd occurring numbers.

            Now find any set bit in xorValue.
            That bit will be different in x and y.

            Divide elements into 2 groups:
            
            1. Bit is set
            2. Bit is not set

            XOR separately to get both numbers.
        */

        int xorValue = 0;

        // XOR all elements
        for (int num : arr) {
            xorValue ^= num;
        }

        /*
            Find rightmost set bit

            Example:
            xorValue = 6 -> 110

            rightmostSetBit = 010
        */
        int rightmostSetBit = xorValue & (-xorValue);

        int num1 = 0;
        int num2 = 0;

        // Divide into 2 groups
        for (int num : arr) {

            if (num & rightmostSetBit) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }

        // Return in decreasing order
        if (num1 > num2) {
            return {num1, num2};
        }

        return {num2, num1};
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

    vector<int> ans = obj.twoOddNum(arr);

    // Output
    cout << ans[0] << " " << ans[1];

    return 0;
}