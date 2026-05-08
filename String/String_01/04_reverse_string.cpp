#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    string reverseString(string s) {

        // Intuition:
        // Use two pointers:
        // 1. One at starting
        // 2. One at ending
        //
        // Swap characters and move inward.

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = obj.reverseString(s);

    cout << "Reversed String: " << result << endl;

    return 0;
}