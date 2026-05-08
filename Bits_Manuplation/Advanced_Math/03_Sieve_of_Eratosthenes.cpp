#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    vector<int> sieveOfEratosthenes(int n) {

        /*
            Intuition:

            Initially assume all numbers are prime.

            Start from 2.

            If a number is prime,
            mark all its multiples as NOT prime.

            Example:

            For 2:
            mark 4, 6, 8, 10 ...

            For 3:
            mark 6, 9, 12 ...

            Remaining unmarked numbers are prime.
        */

        vector<bool> isPrime(n + 1, true);

        // 0 and 1 are not prime
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        /*
            Traverse till sqrt(n)

            Because smaller factors already
            mark larger multiples.
        */
        for (int i = 2; i * i <= n; i++) {

            // If current number is prime
            if (isPrime[i]) {

                /*
                    Mark all multiples of i
                    as non-prime
                */
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;

        // Store all prime numbers
        for (int i = 2; i <= n; i++) {

            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    vector<int> ans = obj.sieveOfEratosthenes(n);

    // Output
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}