#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Intuition:
    //
    // We use Binary Search on the smaller array.
    //
    // We divide both arrays into left and right parts
    // such that:
    //
    // Total elements on left side
    // = Total elements on right side
    //
    // Correct partition condition:
    //
    // left1 <= right2
    // AND
    // left2 <= right1
    //
    // If condition satisfies:
    //
    // Odd total elements:
    // median = max(left1, left2)
    //
    // Even total elements:
    // median =
    // (max(left1, left2) + min(right1, right2)) / 2
    //
    // Time Complexity:
    // O(log(min(n1, n2)))
    //
    // Space Complexity:
    // O(1)

    double medianOfArrays(vector<int>& a, vector<int>& b) {

        int n1 = a.size();
        int n2 = b.size();

        // Always apply binary search
        // on smaller array
        if (n1 > n2) {
            return medianOfArrays(b, a);
        }

        int low = 0;
        int high = n1;

        int total = n1 + n2;

        while (low <= high) {

            int cut1 = low + (high - low) / 2;

            int cut2 = (total + 1) / 2 - cut1;

            int left1 =
                (cut1 == 0)
                ? INT_MIN
                : a[cut1 - 1];

            int left2 =
                (cut2 == 0)
                ? INT_MIN
                : b[cut2 - 1];

            int right1 =
                (cut1 == n1)
                ? INT_MAX
                : a[cut1];

            int right2 =
                (cut2 == n2)
                ? INT_MAX
                : b[cut2];

            // Correct partition found
            if (left1 <= right2 &&
                left2 <= right1) {

                // Odd total elements
                if (total % 2 == 1) {

                    return max(left1, left2);
                }

                // Even total elements
                else {

                    return (max(left1, left2) +
                            min(right1, right2)) / 2.0;
                }
            }

            // Move towards left
            else if (left1 > right2) {

                high = cut1 - 1;
            }

            // Move towards right
            else {

                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {

    int n1;

    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter first sorted array:\n";

    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    int n2;

    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter second sorted array:\n";

    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    Solution obj;

    double result = obj.medianOfArrays(a, b);

    cout << "Median: " << result << endl;

    return 0;
}