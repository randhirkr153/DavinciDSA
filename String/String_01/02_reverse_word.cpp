#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string reverseWords(string s) {

        // Intuition:
        // We need to reverse the order of words,
        // not the characters inside each word.
        //
        // Words are separated by dots(.)
        // There can be:
        // 1. Leading dots
        // 2. Trailing dots
        // 3. Multiple dots between words
        //
        // Approach:
        // Step 1: Extract valid words
        // Step 2: Store words in vector
        // Step 3: Traverse vector in reverse order
        // Step 4: Join words using single dot

        vector<string> words;
        string temp = "";

        // Extract words
        for(char ch : s) {

            if(ch == '.') {

                // If word exists, store it
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

        // Build answer in reverse order
        string ans = "";

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

    cout << "Output: " << result << endl;

    return 0;
}