#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to calculate total hours
    // needed if Koko eats at speed = s
    long long totalHours(vector<int>& arr, int s) {

        long long hours = 0;

        for (int bananas : arr) {

            // Ceiling division
            hours += (bananas + s - 1) / s;
        }

        return hours;
    }

    // Intuition:
    // Minimum eating speed lies between:
    // 1 banana/hour and max pile/hour.
    //
    // We apply Binary Search on speed.
    //
    // If Koko can finish within k hours,
    // try smaller speed.
    //
    // Otherwise,
    // increase speed.
    //
    // Time Complexity: O(n * log(max(arr)))
    // Space Complexity: O(1)

    int kokoEat(vector<int>& arr, int k) {

        int low = 1;

        int high = *max_element(arr.begin(), arr.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = totalHours(arr, mid);

            if (hours <= k) {

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

    cout << "Enter banana piles:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter total hours: ";
    cin >> k;

    Solution obj;

    int result = obj.kokoEat(arr, k);

    cout << "Minimum Eating Speed: " << result << endl;

    return 0;
}