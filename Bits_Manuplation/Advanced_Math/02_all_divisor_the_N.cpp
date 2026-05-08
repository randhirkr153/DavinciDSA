#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
  
    vector<int> divisors(int n) {

        /*
            Intuition:

            Divisors always come in pairs.

            Example:

            n = 20

            1 × 20
            2 × 10
            4 × 5

            So instead of checking till n,
            we check only till sqrt(n).
        */

        vector<int> ans;

        // Check from 1 to sqrt(n)
        for (int i = 1; i * i <= n; i++) {

            // If i divides n
            if (n % i == 0) {

                // First divisor
                ans.push_back(i);

                /*
                    Second divisor

                    Avoid duplicate when:
                    i * i == n
                */
                if (i != n / i) {
                    ans.push_back(n / i);
                }
            }
        }

        // Sort divisors in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    vector<int> ans = obj.divisors(n);

    // Output
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}