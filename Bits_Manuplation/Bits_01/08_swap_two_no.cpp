#include <iostream>
using namespace std;

class Solution {
  public:
  
    void swapNum(int &a, int &b) {

        /*
            Intuition:

            We swap values using XOR operation
            without using extra variable.

            XOR Properties:

            x ^ x = 0
            x ^ 0 = x

            Steps:

            a = a ^ b
            b = a ^ b
            a = a ^ b
        */

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main() {

    int a, b;

    // Input
    cin >> a >> b;

    Solution obj;

    obj.swapNum(a, b);

    // Output
    cout << a << " " << b;

    return 0;
}