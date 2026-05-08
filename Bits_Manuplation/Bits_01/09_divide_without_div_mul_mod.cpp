#include <iostream>
#include <climits>
using namespace std;

class Solution {
  public:
  
    int divide(int dividend, int divisor) {

        /*
            Intuition:

            We cannot use:
            *, /, %

            So we use BIT MANIPULATION.

            Division means repeated subtraction.

            Instead of subtracting one by one,
            we subtract large powers of 2.

            Example:
            
            40 / 5
            
            5 * 8 = 40
            
            Using shifts:
            5 << 3 = 40
            
            So quotient += 8
        */

        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and make positive
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        /*
            Keep subtracting biggest possible
            shifted divisor.
        */
        while (dvd >= dvs) {

            long long temp = dvs;
            long long multiple = 1;

            /*
                Double the divisor until it
                becomes greater than dividend.
            */
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract largest chunk
            dvd -= temp;

            // Add corresponding quotient
            quotient += multiple;
        }

        // Apply sign
        if (negative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};

int main() {

    int dividend, divisor;

    // Input
    cin >> dividend >> divisor;

    Solution obj;

    // Output
    cout << obj.divide(dividend, divisor);

    return 0;
}