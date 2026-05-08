#include <iostream>
#include <climits>
using namespace std;

//like 32 bit integers 

class Solution {
public:

    int myAtoi(string s) {

        // Intuition:
        // Step 1:
        // Ignore leading spaces
        //
        // Step 2:
        // Check sign (+ or -)
        //
        // Step 3:
        // Read digits until non-digit comes
        //
        // Step 4:
        // Handle overflow conditions

        int i = 0;
        int n = s.length();

        // Skip leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;

        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            i++;
        }

        long long ans = 0;

        // Read digits
        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // Handle overflow
            if(sign * ans > INT_MAX) {
                return INT_MAX;
            }

            if(sign * ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * ans);
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    int result = obj.myAtoi(s);

    cout << "Integer Value: " << result << endl;

    return 0;
}