#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool areAnagrams(string s1, string s2) {

        // Intuition:
        // Two strings are anagrams if:
        // 1. Lengths are same
        // 2. Frequency of every character is same
        //
        // Use frequency array of size 26.
        //
        // Increase count for s1 characters
        // Decrease count for s2 characters
        //
        // If all frequencies become 0,
        // strings are anagrams.

        // Length check
        if(s1.length() != s2.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        // Count frequencies
        for(int i = 0; i < s1.length(); i++) {

            freq[s1[i] - 'a']++;

            freq[s2[i] - 'a']--;
        }

        // Check all frequencies
        for(int count : freq) {

            if(count != 0) {
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

    bool result = obj.areAnagrams(s1, s2);

    if(result) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}