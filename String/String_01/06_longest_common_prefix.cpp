#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string>& arr) {

        // Intuition:
        // Take first string as reference.
        //
        // Compare each character of first string
        // with same position characters
        // in all other strings.
        //
        // If mismatch occurs,
        // return prefix formed till now.

        string ans = "";

        // First string
        string first = arr[0];

        for(int i = 0; i < first.length(); i++) {

            char ch = first[i];

            // Check in all strings
            for(int j = 1; j < arr.size(); j++) {

                // Out of bounds OR mismatch
                if(i >= arr[j].length() || arr[j][i] != ch) {
                    return ans;
                }
            }

            // Character common in all strings
            ans += ch;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);

    cout << "Enter strings:" << endl;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string result = obj.longestCommonPrefix(arr);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}