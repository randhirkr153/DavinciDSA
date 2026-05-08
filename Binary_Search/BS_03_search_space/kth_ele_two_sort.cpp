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
    // We divide arrays into two parts such that:
    //
    // left part contains exactly k elements.
    //
    // We check:
    //
    // left1 <= right2
    // AND
    // left2 <= right1
    //
    // If true:
    // kth element = max(left1, left2)
    //
    // Else adjust binary search.
    //
    // Time Complexity:
    // O(log(min(n1, n2)))
    //
    // Space Complexity:
    // O(1)

    int kthElement(vector<int>& a,
                   vector<int>& b,
                   int k) {

        int n1 = a.size();
        int n2 = b.size();

        // Always binary search
        // on smaller array
        if (n1 > n2) {
            return kthElement(b, a, k);
        }

        int low = max(0, k - n2);

        int high = min(k, n1);

        while (low <= high) {

            int cut1 =
                low + (high - low) / 2;

            int cut2 = k - cut1;

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

            // Correct partition
            if (left1 <= right2 &&
                left2 <= right1) {

                return max(left1, left2);
            }

            // Move left
            else if (left1 > right2) {

                high = cut1 - 1;
            }

            // Move right
            else {

                low = cut1 + 1;
            }
        }

        return -1;
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

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int result =
        obj.kthElement(a, b, k);

    cout << "K-th Element: "
         << result << endl;

    return 0;
}