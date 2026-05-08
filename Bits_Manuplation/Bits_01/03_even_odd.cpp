#include <iostream>
using namespace std;

class Solution {
public:

    bool isEven(int n) {

        /*
            Intuition:

            In binary numbers:

            Even number  -> last bit is 0
            Odd number   -> last bit is 1

            We can check last bit using:
            n & 1

            If result is 1 -> odd
            If result is 0 -> even
        */

        if ((n & 1) == 0) {
            return true;   // Even
        }

        return false;      // Odd
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    bool ans = obj.isEven(n);

    // Output
    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}