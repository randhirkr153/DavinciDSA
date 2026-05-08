#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    vector<int> AllPrimeFactors(int n) {

        /*
            Intuition:

            A factor divides the number completely.

            We check every number from 2 to sqrt(n).

            If a number divides n:
            it is a prime factor.

            Keep dividing n completely
            to avoid duplicates.

            Example:

            n = 60

            60 / 2 = 30
            30 / 2 = 15

            Store 2 only once.
        */

        vector<int> ans;

        // Check factors from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {

            // If i divides n
            if (n % i == 0) {

                // Store unique prime factor
                ans.push_back(i);

                /*
                    Remove all occurrences
                    of this factor
                */
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        /*
            If n > 1,
            then n itself is prime.
        */
        if (n > 1) {
            ans.push_back(n);
        }

        return ans;
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    vector<int> ans = obj.AllPrimeFactors(n);

    // Output
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}