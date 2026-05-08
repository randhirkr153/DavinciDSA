#include <iostream>
using namespace std;

class Solution {
  public:
  
    int setBit(int n) {

        /*
            Intuition:

            We need to set the RIGHTMOST unset bit.

            Trick:
            n | (n + 1)

            Why?

            Adding 1 changes the rightmost 0 bit to 1.
            OR operation keeps all previous bits
            and sets that unset bit.

            Example:
            
            n = 6
            
            6  = 110
            7  = 111
            
            OR:
            110
            111
            ---
            111 = 7
        */

        return (n | (n + 1));
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    // Output
    cout << obj.setBit(n);

    return 0;
}