#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string reverseWords(string s) {

        // Intuition:
        // Step 1:
        // Extract valid words separated by '.'
        //
        // Step 2:
        // Ignore extra dots
        //
        // Step 3:
        // Reverse order of words
        //
        // Step 4:
        // Join words using single dot

        vector<string> words;

        string temp = "";

        // Extract words
        for(char ch : s) {

            if(ch == '.') {

                // Store valid word
                if(temp != "") {
                    words.push_back(temp);
                    temp = "";
                }
            }
            else {
                temp += ch;
            }
        }

        // Last word
        if(temp != "") {
            words.push_back(temp);
        }

        string ans = "";

        // Reverse words
        for(int i = words.size() - 1; i >= 0; i--) {

            ans += words[i];

            // Add dot between words
            if(i != 0) {
                ans += '.';
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = obj.reverseWords(s);

    cout << "Reversed String: " << result << endl;

    return 0;
}