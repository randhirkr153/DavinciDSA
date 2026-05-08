#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        // Intuition:
        // Store all elements in a hash set
        // for O(1) lookup.
        //
        // A number starts a sequence only if
        // (number - 1) does not exist.
        //
        // Then keep checking consecutive numbers
        // and count sequence length.
        //
        // Track maximum length.

        unordered_set<int> st;

        // Insert all elements into set
        for (int num : arr) {
            st.insert(num);
        }

        int longest = 0;

        for (int num : arr) {

            // Start of sequence
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int count = 1;

                // Count consecutive numbers
                while (st.find(currentNum + 1) != st.end()) {

                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Longest Consecutive Subsequence Length: "
         << obj.longestConsecutive(arr);

    return 0;
}