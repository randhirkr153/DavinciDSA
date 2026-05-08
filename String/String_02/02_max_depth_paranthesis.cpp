#include <iostream>
using namespace std;

class Solution {
public:

    int maxDepth(string s) {

        // Intuition:
        // Whenever '(' comes,
        // nesting depth increases.
        //
        // Whenever ')' comes,
        // nesting depth decreases.
        //
        // Track maximum depth reached.

        int currentDepth = 0;
        int maxDepth = 0;

        for(char ch : s) {

            // Opening bracket
            if(ch == '(') {

                currentDepth++;

                // Update maximum depth
                maxDepth = max(maxDepth, currentDepth);
            }

            // Closing bracket
            else if(ch == ')') {

                currentDepth--;
            }
        }

        return maxDepth;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter expression: ";
    cin >> s;

    int result = obj.maxDepth(s);

    cout << "Maximum Nesting Depth: " << result << endl;

    return 0;
}