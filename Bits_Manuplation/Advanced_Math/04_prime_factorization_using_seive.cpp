#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    vector<int> findPrimeFactors(int N) {

        /*
            Intuition:

            We use Sieve concept to store
            the Smallest Prime Factor (SPF)
            for every number.

            Example:

            SPF[12] = 2
            SPF[15] = 3

            Then repeatedly divide the number
            using SPF to get prime factors.
        */

        vector<int> spf(N + 1);

        /*
            Initially every number is its own SPF.
        */
        for (int i = 0; i <= N; i++) {
            spf[i] = i;
        }

        /*
            Build SPF array using Sieve.
        */
        for (int i = 2; i * i <= N; i++) {

            // If i is prime
            if (spf[i] == i) {

                /*
                    Mark SPF for multiples
                */
                for (int j = i * i; j <= N; j += i) {

                    // Set SPF only first time
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        vector<int> ans;

        /*
            Get prime factors using SPF.
        */
        while (N > 1) {

            int primeFactor = spf[N];

            ans.push_back(primeFactor);

            // Divide by SPF
            N = N / primeFactor;
        }

        return ans;
    }
};

int main() {

    int N;

    // Input
    cin >> N;

    Solution obj;

    vector<int> ans = obj.findPrimeFactors(N);

    // Output
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}