#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {

        // Intuition:
        // Use two pointers for both sorted arrays.
        //
        // Compare elements:
        // - Smaller element is added to answer.
        // - If equal, add only once and move both pointers.
        //
        // To avoid duplicates:
        // Add element only if it is different
        // from last inserted element.

        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i < a.size() && j < b.size()) {

            if (a[i] < b[j]) {

                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }

                i++;
            }

            else if (a[i] > b[j]) {

                if (ans.empty() || ans.back() != b[j]) {
                    ans.push_back(b[j]);
                }

                j++;
            }

            else {

                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }

                i++;
                j++;
            }
        }

        // Remaining elements of array a
        while (i < a.size()) {

            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }

            i++;
        }

        // Remaining elements of array b
        while (j < b.size()) {

            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }

            j++;
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

    vector<int> result = obj.findUnion(a, b);

    cout << "Union of arrays: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}