#include <iostream>
using namespace std;

class Solution {
public:
    
    string removeOuter(string s) {
        
        // Intuition:
        // We remove the outermost brackets
        // from every primitive valid parentheses string.
        //
        // balance = number of currently open brackets.
        //
        // For '(' :
        //   If balance > 0 -> not outermost, add it.
        //   Then increase balance.
        //
        // For ')' :
        //   First decrease balance.
        //   If balance > 0 -> not outermost, add it.

        string ans = "";
        int balance = 0;

        for(char ch : s) {

            // Opening bracket
            if(ch == '(') {

                // Not outermost
                if(balance > 0) {
                    ans += ch;
                }

                balance++;
            }

            // Closing bracket
            else {

                balance--;

                // Not outermost
                if(balance > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    string result = obj.removeOuter(s);

    cout << "Answer: " << result << endl;

    return 0;
}