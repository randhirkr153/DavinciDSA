#include <iostream>
using namespace std;

class Solution {
public:

    // Expand from center and return palindrome length
    int expand(string &s, int left, int right) {

        while(left >= 0 &&
              right < s.length() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        // Length of palindrome
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        // Intuition:
        // Every palindrome expands from center.
        //
        // Two cases:
        // 1. Odd length palindrome  -> center at one char
        // 2. Even length palindrome -> center between chars
        //
        // Expand around every index
        // and keep track of longest palindrome.

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            // Update longest palindrome
            if(len > maxLen) {

                maxLen = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = obj.longestPalindrome(s);

    cout << "Longest Palindrome: " << result << endl;

    return 0;
}