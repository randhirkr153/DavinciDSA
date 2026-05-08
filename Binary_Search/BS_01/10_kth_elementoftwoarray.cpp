#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int kthElement(vector<int>& a, vector<int>& b, int k) {

        int n1 = a.size();
        int n2 = b.size();

        // Always apply binary search on smaller array
        if (n1 > n2) {
            return kthElement(b, a, k);
        }

        /*
            cut1 -> elements taken from array a
            cut2 -> elements taken from array b

            cut1 + cut2 = k
        */

        int low = max(0, k - n2);
        int high = min(k, n1);

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;

            int left1  = (cut1 == 0)  ? INT_MIN : a[cut1 - 1];
            int left2  = (cut2 == 0)  ? INT_MIN : b[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : b[cut2];

            /*
                Correct partition:

                left elements <= right elements
            */

            if (left1 <= right2 && left2 <= right1) {

                return max(left1, left2);
            }

            // Too many elements taken from a[]
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // Take more elements from a[]
            else {
                low = cut1 + 1;
            }
        }

        return -1;
    }
};

int main() {

    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    int k = 5;

    Solution obj;

    cout << obj.kthElement(a, b, k);

    return 0;
}