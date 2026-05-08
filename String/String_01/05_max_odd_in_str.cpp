#include <iostream>
using namespace std;

class Solution {
public:

    string maxOdd(string s) {

        // Intuition:
        // Largest odd substring will always end
        // at an odd digit.
        //
        // We traverse from right to left.
        // First odd digit found gives the answer.
        //
        // Return substring from 0 to that index.

        for(int i = s.length() - 1; i >= 0; i--) {

            // Check odd digit
            if((s[i] - '0') % 2 == 1) {

                // Return substring till i
                return s.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter number string: ";
    cin >> s;

    string result = obj.maxOdd(s);

    cout << "Largest Odd Substring: " << result << endl;

    return 0;
}