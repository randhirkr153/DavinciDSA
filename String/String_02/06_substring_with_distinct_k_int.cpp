#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Function to count substrings
    // with at most k distinct characters
    int atMostK(string s, int k) {

        if(k < 0) {
            return 0;
        }

        int left = 0;
        int count = 0;

        vector<int> freq(26, 0);

        int distinct = 0;

        for(int right = 0; right < s.length(); right++) {

            // Add current character
            if(freq[s[right] - 'a'] == 0) {
                distinct++;
            }

            freq[s[right] - 'a']++;

            // Shrink window if distinct > k
            while(distinct > k) {

                freq[s[left] - 'a']--;

                if(freq[s[left] - 'a'] == 0) {
                    distinct--;
                }

                left++;
            }

            // Number of valid substrings
            count += (right - left + 1);
        }

        return count;
    }

    int countSubstr(string s, int k) {

        // Intuition:
        // Exactly K distinct =
        // AtMost(K) - AtMost(K-1)
        //
        // Sliding window is used
        // to count substrings efficiently.

        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {

    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int result = obj.countSubstr(s, k);

    cout << "Total Substrings: " << result << endl;

    return 0;
}