#include <iostream>
using namespace std;

class Solution {
  public:

    // Function to calculate power using Binary Exponentiation
    long long power(long long base, long long exp) {

        /*
            Intuition:

            Instead of multiplying base
            exp times,

            use Binary Exponentiation.

            If exponent is even:
            a^b = (a*a)^(b/2)

            If exponent is odd:
            multiply answer by base.
        */

        long long ans = 1;

        while (exp > 0) {

            // If exponent is odd
            if (exp & 1) {
                ans = ans * base;
            }

            // Square the base
            base = base * base;

            // Divide exponent by 2
            exp = exp >> 1;
        }

        return ans;
    }

    int reverseNumber(int n) {

        /*
            Reverse the digits of number.
        */

        int rev = 0;

        while (n > 0) {

            int digit = n % 10;

            rev = rev * 10 + digit;

            n = n / 10;
        }

        return rev;
    }

    long long powerOfNumber(int n) {

        /*
            Step 1:
            Find reverse of n

            Step 2:
            Calculate n^(reverse)
        */

        int rev = reverseNumber(n);

        return power(n, rev);
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    // Output
    cout << obj.powerOfNumber(n);

    return 0;
}