#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
  
    vector<string> AllPossibleStrings(string s) {

        /*
            Intuition:

            Every character has 2 choices:

            1. Include it
            2. Exclude it

            Total subsequences:
            2^n

            We use BIT MANIPULATION.

            For every number from:
            1 to (2^n - 1)

            Binary representation tells
            which characters to pick.

            Example:

            s = "abc"

            mask = 5 -> 101

            pick:
            a and c

            subsequence = "ac"
        */

        int n = s.length();

        vector<string> ans;

        // Generate all masks
        for (int mask = 1; mask < (1 << n); mask++) {

            string temp = "";

            // Check every bit
            for (int i = 0; i < n; i++) {

                /*
                    If ith bit is set,
                    include s[i]
                */
                if (mask & (1 << i)) {
                    temp += s[i];
                }
            }

            ans.push_back(temp);
        }

        // Sort lexicographically
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    string s;

    // Input
    cin >> s;

    Solution obj;

    vector<string> ans = obj.AllPossibleStrings(s);

    // Output
    for (string str : ans) {
        cout << str << " ";
    }

    return 0;
}