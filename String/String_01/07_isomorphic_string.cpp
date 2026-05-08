#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool areIsomorphic(string s1, string s2) {

        // Intuition:
        // Each character of s1 should map
        // to only one character of s2.
        //
        // Also, two different characters
        // of s1 cannot map to same character in s2.
        //
        // Use two arrays:
        // map1 -> mapping from s1 to s2
        // map2 -> checks already mapped chars in s2

        vector<char> map1(256, 0);
        vector<bool> map2(256, false);

        for(int i = 0; i < s1.length(); i++) {

            char ch1 = s1[i];
            char ch2 = s2[i];

            // Mapping not created yet
            if(map1[ch1] == 0) {

                // ch2 already mapped with another char
                if(map2[ch2] == true) {
                    return false;
                }

                // Create mapping
                map1[ch1] = ch2;
                map2[ch2] = true;
            }

            // Existing mapping mismatch
            else if(map1[ch1] != ch2) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    bool result = obj.areIsomorphic(s1, s2);

    if(result) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}