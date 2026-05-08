#include <iostream>
using namespace std;

class Solution {
public:

    // Function to calculate mid^n
    long long power(long long mid, int n) {

        long long ans = 1;

        for (int i = 0; i < n; i++) {
            ans *= mid;
        }

        return ans;
    }

    // Intuition:
    // We use Binary Search from 1 to m.
    //
    // For every mid:
    // calculate mid^n
    //
    // If mid^n == m
    // then mid is the nth root.
    //
    // If mid^n < m
    // move right side.
    //
    // If mid^n > m
    // move left side.
    //
    // If no integer root exists,
    // return -1.
    //
    // Time Complexity: O(n * log m)
    // Space Complexity: O(1)

    int nthRoot(int n, int m) {

        int low = 1;
        int high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long value = power(mid, n);

            if (value == m) {
                return mid;
            }

            else if (value < m) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    Solution obj;

    int result = obj.nthRoot(n, m);

    cout << "Nth Root: " << result << endl;

    return 0;
}