#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to calculate days needed
    // for a given ship capacity
    int daysNeeded(vector<int>& arr, int capacity) {

        int days = 1;
        int load = 0;

        for (int weight : arr) {

            // Add weight to current day
            if (load + weight <= capacity) {

                load += weight;
            }

            // Move to next day
            else {

                days++;
                load = weight;
            }
        }

        return days;
    }

    // Intuition:
    // Minimum capacity must be at least
    // max element because one package
    // cannot be split.
    //
    // Maximum capacity can be sum of all weights.
    //
    // We apply Binary Search on capacity.
    //
    // If packages can be shipped within d days,
    // try smaller capacity.
    //
    // Else increase capacity.
    //
    // Time Complexity:
    // O(n * log(sum(arr)))
    //
    // Space Complexity:
    // O(1)

    int leastWeightCapacity(vector<int>& arr, int d) {

        int low = *max_element(arr.begin(), arr.end());

        int high = 0;

        for (int weight : arr) {
            high += weight;
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = daysNeeded(arr, mid);

            if (requiredDays <= d) {

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

    cout << "Enter package weights:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;

    cout << "Enter number of days: ";
    cin >> d;

    Solution obj;

    int result = obj.leastWeightCapacity(arr, d);

    cout << "Minimum Ship Capacity: " << result << endl;

    return 0;
}