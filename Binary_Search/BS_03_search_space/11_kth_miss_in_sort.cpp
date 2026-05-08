#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Intuition:
    //
    // For every pair of adjacent elements,
    // calculate how many numbers are missing.
    //
    // Missing count between:
    // arr[i-1] and arr[i]
    //
    // = arr[i] - arr[i-1] - 1
    //
    // If k is smaller than or equal to
    // missing count,
    // answer lies in this gap.
    //
    // Otherwise reduce k and continue.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int kthMissing(vector<int>& arr, int k) {

        int n = arr.size();

        for (int i = 1; i < n; i++) {

            int missing =
                arr[i] - arr[i - 1] - 1;

            // Answer lies in current gap
            if (k <= missing) {

                return arr[i - 1] + k;
            }

            // Reduce k
            k -= missing;
        }

        // No kth missing element
        return -1;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int result = obj.kthMissing(arr, k);

    cout << "K-th Missing Element: "
         << result << endl;

    return 0;
}