#include <iostream>
using namespace std;

class Solution {
public:

    bool areRotations(string s1, string s2) {

        // Intuition:
        // If s2 is rotation of s1,
        // then s2 must be present
        // inside s1 + s1
        //
        // Example:
        // s1 = "abcd"
        // s1+s1 = "abcdabcd"
        //
        // s2 = "cdab"
        // "cdab" exists in "abcdabcd"

        // Lengths must be equal
        if(s1.length() != s2.length()) {
            return false;
        }

        // Concatenate s1 with itself
        string temp = s1 + s1;

        // Find s2 in temp
        if(temp.find(s2) != string::npos) {
            return true;
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    bool result = obj.areRotations(s1, s2);

    if(result) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}