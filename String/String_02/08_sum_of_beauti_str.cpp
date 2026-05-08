#include <iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:

    int beautySum(string s) {

        // Intuition:
        // Generate all substrings.
        //
        // For every substring:
        // 1. Count frequency of characters
        // 2. Find maximum frequency
        // 3. Find minimum frequency
        // 4. Beauty = maxFreq - minFreq
        //
        // Add beauty of all substrings.

        int n = s.length();

        int totalBeauty = 0;

        // Starting index
        for(int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            // Ending index
            for(int j = i; j < n; j++) {

                // Add current character
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Find max and min frequency
                for(int k = 0; k < 26; k++) {

                    if(freq[k] > 0) {

                        maxFreq = max(maxFreq, freq[k]);

                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // Add beauty
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = obj.beautySum(s);

    cout << "Sum of Beauty: " << result << endl;

    return 0;
}