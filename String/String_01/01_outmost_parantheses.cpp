#include <iostream>
using namespace std;


        
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
class Solution {
public:
    string removeOuter(string& s) {
        // code here
        
        string ans = "";
        stack<char> st;

        for (char ch : s) {

            if (ch == ')')
                st.pop();

            if (!(st.empty()))
                ans += ch;

            if (ch == '(')
                st.push(ch);
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
