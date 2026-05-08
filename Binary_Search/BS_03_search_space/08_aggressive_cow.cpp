#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to check if we can place
    // all cows with minimum distance = dist
    bool canPlaceCows(vector<int>& stalls,
                       int k,
                       int dist) {

        int cowsPlaced = 1;

        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {

            // Place next cow
            if (stalls[i] - lastPosition >= dist) {

                cowsPlaced++;

                lastPosition = stalls[i];
            }

            // All cows placed
            if (cowsPlaced >= k) {
                return true;
            }
        }

        return false;
    }

    // Intuition:
    // We want to maximize the minimum distance
    // between any two cows.
    //
    // Sort the stall positions first.
    //
    // Minimum possible distance = 1
    // Maximum possible distance =
    // last stall - first stall
    //
    // Apply Binary Search on distance.
    //
    // If cows can be placed with mid distance,
    // try larger distance.
    //
    // Else reduce distance.
    //
    // Time Complexity:
    // O(n * log(maxDistance))
    //
    // Space Complexity:
    // O(1)

    int aggressiveCows(vector<int>& stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int low = 1;

        int high = stalls.back() - stalls.front();

        int ans = 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {

                ans = mid;

                // Try bigger distance
                low = mid + 1;
            }

            else {

                // Reduce distance
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);

    cout << "Enter stall positions:\n";

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int k;

    cout << "Enter number of cows: ";
    cin >> k;

    Solution obj;

    int result = obj.aggressiveCows(stalls, k);

    cout << "Largest Minimum Distance: "
         << result << endl;

    return 0;
}