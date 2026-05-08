#include <iostream>
using namespace std;

class Solution {
  public:
  
    int countBitsFlip(int a, int b) {

        /*
            Intuition:

            We need positions where bits are different.

            XOR (^) gives 1 where bits differ.

            Example:

            a = 10 -> 01010
            b = 20 -> 10100

            XOR:
            01010
            10100
            -----
            11110

            Now count set bits in XOR result.
            Those are the bits to flip.
        */

        int xorValue = a ^ b;

        int count = 0;

        /*
            Use Brian Kernighan Algorithm

            x & (x - 1)

            removes the last set bit.
        */

        while (xorValue > 0) {

            xorValue = xorValue & (xorValue - 1);

            count++;
        }

        return count;
    }
};

int main() {

    int a, b;

    // Input
    cin >> a >> b;

    Solution obj;

    // Output
    cout << obj.countBitsFlip(a, b);

    return 0;
}