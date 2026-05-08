#include <iostream>
using namespace std;

class Solution {
public:

    // Intuition:
    // We use Binary Search on numbers from 1 to n.
    //
    // If mid * mid == n
    // then mid is the square root.
    //
    // If mid * mid < n
    // then answer may exist on right side.
    // Store mid as possible answer.
    //
    // If mid * mid > n
    // then move to left side.
    //
    // Finally, answer stores floor square root.
    //
    // Time Complexity: O(log n)
    // Space Complexity: O(1)

    int floorSqrt(int n) {

        int low = 1;
        int high = n;

        int ans = 0;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            long long square = mid * mid;

            if (square == n) {
                return mid;
            }

            else if (square < n) {
                ans = mid;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number: ";
    cin >> n;

    Solution obj;

    int result = obj.floorSqrt(n);

    cout << "Floor Square Root: " << result << endl;

    return 0;
}