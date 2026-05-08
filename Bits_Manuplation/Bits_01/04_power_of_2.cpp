#include <iostream>
using namespace std;

class Solution {
  public:
  
    bool isPowerofTwo(int n) {

        /*
            Intuition:

            Power of 2 numbers contain only ONE set bit.

            Example:

            1  -> 0001
            2  -> 0010
            4  -> 0100
            8  -> 1000

            Trick:

            n & (n - 1)

            removes the last set bit.

            For powers of 2:
            result becomes 0.

            Example:
            
            n = 8
            
            1000
            0111
            ----
            0000
        */

        // 0 is not a power of 2
        if (n == 0) {
            return false;
        }

        // check if only one set bit exists
        if ((n & (n - 1)) == 0) {
            return true;
        }

        return false;
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    bool ans = obj.isPowerofTwo(n);

    // Output
    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}