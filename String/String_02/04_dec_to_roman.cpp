#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string intToRoman(int num) {

        // Intuition:
        // Store Roman values from largest to smallest.
        //
        // Repeatedly subtract value from number
        // and add corresponding Roman symbol.

        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string ans = "";

        for(int i = 0; i < values.size(); i++) {

            // Add symbol while value fits
            while(num >= values[i]) {

                ans += symbols[i];

                num -= values[i];
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int num;

    cout << "Enter number: ";
    cin >> num;

    string result = obj.intToRoman(num);

    cout << "Roman Number: " << result << endl;

    return 0;
}