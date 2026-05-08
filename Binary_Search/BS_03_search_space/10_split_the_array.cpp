#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Intuition:
    //
    // We need maximum subarray sum
    // with size AT LEAST k.
    //
    // Step 1:
    // Use Kadane's idea to store
    // maximum sum ending at every index.
    //
    // maxEnd[i] =
    // maximum subarray sum ending at i
    //
    // Step 2:
    // Calculate sum of every window
    // of size exactly k.
    //
    // Step 3:
    // For every window of size k,
    // we can extend it using previous
    // positive sum from maxEnd[].
    //
    // Final answer:
    // max(windowSum,
    //     windowSum + maxEnd[i-k])
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    long long maxSumWithK(vector<long long>& a,
                          long long n,
                          long long k) {

        vector<long long> maxEnd(n);

        // Kadane preprocessing
        maxEnd[0] = a[0];

        for (int i = 1; i < n; i++) {

            maxEnd[i] = max(a[i],
                            maxEnd[i - 1] + a[i]);
        }

        // First window of size k
        long long windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += a[i];
        }

        long long ans = windowSum;

        // Remaining windows
        for (int i = k; i < n; i++) {

            // Slide window
            windowSum += a[i] - a[i - k];

            // Exact size k
            ans = max(ans, windowSum);

            // More than k size
            ans = max(ans,
                      windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};

int main() {

    long long n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<long long> a(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    long long result =
        obj.maxSumWithK(a, n, k);

    cout << "Largest Sum Subarray "
         << "with at least k elements: "
         << result << endl;

    return 0;
}