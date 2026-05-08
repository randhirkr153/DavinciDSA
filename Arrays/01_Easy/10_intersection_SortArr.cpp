#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {

        // Intuition:
        // Use two pointers for both sorted arrays.
        //
        // If elements are equal:
        // add element only once and move both pointers.
        //
        // If a[i] < b[j]:
        // move pointer i.
        //
        // If b[j] < a[i]:
        // move pointer j.
        //
        // This gives common distinct elements
        // in sorted order.

        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i < a.size() && j < b.size()) {

            if (a[i] < b[j]) {
                i++;
            }

            else if (a[i] > b[j]) {
                j++;
            }

            else {

                // Avoid duplicates
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter first sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter second sorted array elements: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    Solution obj;

    vector<int> result = obj.intersection(a, b);

    cout << "Intersection of arrays: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}