#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> nthRowOfPascalTriangle(int n) {

        // Intuition:
        // We know:
        // Every row starts and ends with 1.
        //
        // Instead of using factorial formula:
        // nCr = n! / (r! * (n-r)!)
        //
        // We generate next element from previous element:
        //
        // next = current * (n-r) / r
        //
        // Example:
        // n = 5
        // Row = 1 4 6 4 1
        //
        // Start with 1
        // 1 * 4 / 1 = 4
        // 4 * 3 / 2 = 6
        // 6 * 2 / 3 = 4
        // 4 * 1 / 4 = 1
        //
        // Time Complexity: O(n)
        // Space Complexity: O(n)

        vector<int> ans;

        long long val = 1;

        // First element always 1
        ans.push_back(1);

        // Generate remaining elements
        for (int r = 1; r < n; r++) {

            val = val * (n - r);
            val = val / r;

            ans.push_back(val);
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter row number: ";
    cin >> n;

    Solution obj;

    vector<int> result = obj.nthRowOfPascalTriangle(n);

    cout << "Pascal Triangle Row: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}