#include <iostream>
using namespace std;

class Solution {
public:
    void bitManipulation(int num, int i) {

        /*
            Intuition:
            We create a mask using (1 << (i-1))

            Example:
            i = 3

            1 << 2 = 00000100

            This helps us access the 3rd bit.
        */

        // ---------------- GET ith BIT ----------------
        /*
            Step:
            1. Shift ith bit to last position
            2. AND with 1 to extract it
        */

        int getBit = (num >> (i - 1)) & 1;

        // ---------------- SET ith BIT ----------------
        /*
            OR operation with mask sets the ith bit to 1.

            Example:
            1000110
            0000100
            -------
            1000110
        */

        int setBit = num | (1 << (i - 1));

        // ---------------- CLEAR ith BIT ----------------
        /*
            First create mask with 0 at ith position.

            mask = ~(1 << (i-1))

            Then AND with number to clear bit.
        */

        int clearBit = num & ~(1 << (i - 1));

        // print answers
        cout << getBit << " " << setBit << " " << clearBit << endl;
    }
};

int main() {

    int num, i;

    // input
    cin >> num >> i;

    Solution obj;
    obj.bitManipulation(num, i);

    return 0;
}