#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to check if it is possible
    // to make m bouquets in given days
    bool canMakeBouquets(vector<int>& arr, int m, int k, int days) {

        int flowers = 0;
        int bouquets = 0;

        for (int bloomDay : arr) {

            // Flower has bloomed
            if (bloomDay <= days) {

                flowers++;

                // Make one bouquet
                if (flowers == k) {

                    bouquets++;
                    flowers = 0;
                }
            }

            // Flower not bloomed
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    // Intuition:
    // Minimum day lies between:
    // min(arr) and max(arr)
    //
    // We apply Binary Search on days.
    //
    // If bouquets can be made on mid day,
    // try smaller day.
    //
    // Else increase days.
    //
    // Time Complexity:
    // O(n * log(max(arr)))
    //
    // Space Complexity:
    // O(1)

    int minDays(vector<int>& arr, int m, int k) {

        long long totalFlowersNeeded = 1LL * m * k;

        // Impossible case
        if (totalFlowersNeeded > arr.size()) {
            return -1;
        }

        int low = *min_element(arr.begin(), arr.end());

        int high = *max_element(arr.begin(), arr.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canMakeBouquets(arr, m, k, mid)) {

                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter bloom days:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m, k;

    cout << "Enter number of bouquets (m): ";
    cin >> m;

    cout << "Enter flowers needed per bouquet (k): ";
    cin >> k;

    Solution obj;

    int result = obj.minDays(arr, m, k);

    cout << "Minimum Days: " << result << endl;

    return 0;
}