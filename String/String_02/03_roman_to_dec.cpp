#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int romanToDecimal(string s) {

        // Intuition:
        // Roman symbols usually add values.
        //
        // But if smaller value comes before
        // bigger value, subtract it.
        //
        // Example:
        // IV = 5 - 1 = 4
        // IX = 10 - 1 = 9
        //
        // Traverse string:
        // If current value < next value
        // subtract current value
        // else add current value

        unordered_map<char, int> value;

        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < s.length(); i++) {

            // Current value
            int curr = value[s[i]];

            // Next value
            int next = 0;

            if(i + 1 < s.length()) {
                next = value[s[i + 1]];
            }

            // Subtraction case
            if(curr < next) {
                ans -= curr;
            }

            // Addition case
            else {
                ans += curr;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter Roman Number: ";
    cin >> s;

    int result = obj.romanToDecimal(s);

    cout << "Integer Value: " << result << endl;

    return 0;
}