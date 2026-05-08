#include <iostream>
using namespace std;

class Solution {
public:

    // Function to check palindrome
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        // Compare characters from both sides
        while(left < right) {

            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    if(obj.isPalindrome(s)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}