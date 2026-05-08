#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> allPairs(vector<int>& a, vector<int>& b, int target) {

        // Intuition:
        // Store all elements of second array in a hash set.
        //
        // For every element x in first array,
        // check whether (target - x) exists in set.
        //
        // If yes, then pair exists.
        //
        // Finally sort pairs according to first element.

        unordered_set<int> st;

        // Store elements of b in set
        for (int num : b) {
            st.insert(num);
        }

        vector<pair<int, int>> ans;

        // Find valid pairs
        for (int num : a) {

            int needed = target - num;

            if (st.find(needed) != st.end()) {
                ans.push_back({num, needed});
            }
        }

        // Sort according to first element
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter first array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter second array elements: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int target;

    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;

    vector<pair<int, int>> result =
        obj.allPairs(a, b, target);

    cout << "Pairs are:\n";

    for (auto p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}