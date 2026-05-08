#include <iostream>
using namespace std;

class Solution {
  public:

    /*
        Intuition:

        XOR from 1 to n follows pattern:

        n % 4 == 0 -> n
        n % 4 == 1 -> 1
        n % 4 == 2 -> n + 1
        n % 4 == 3 -> 0

        Example:

        1 ^ 2 ^ 3 ^ 4 = 4
    */

    int xorTillN(int n) {

        if (n % 4 == 0)
            return n;

        if (n % 4 == 1)
            return 1;

        if (n % 4 == 2)
            return n + 1;

        return 0;
    }

    int findXOR(int L, int R) {

        /*
            XOR of range [L, R]

            = XOR(1 to R) ^ XOR(1 to L-1)

            Common elements cancel out.
        */

        return xorTillN(R) ^ xorTillN(L - 1);
    }
};

int main() {

    int L, R;

    // Input
    cin >> L >> R;

    Solution obj;

    // Output
    cout << obj.findXOR(L, R);

    return 0;
}