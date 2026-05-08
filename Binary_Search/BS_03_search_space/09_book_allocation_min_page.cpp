#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to check if allocation
    // is possible with maxPages limit
    bool canAllocate(vector<int>& arr,
                     int k,
                     int maxPages) {

        int students = 1;

        int pages = 0;

        for (int book : arr) {

            // Add current book
            if (pages + book <= maxPages) {

                pages += book;
            }

            // Assign to next student
            else {

                students++;

                pages = book;
            }
        }

        return students <= k;
    }

    // Intuition:
    // Minimum possible answer =
    // maximum pages in a single book.
    //
    // Maximum possible answer =
    // sum of all pages.
    //
    // We apply Binary Search on answer.
    //
    // If allocation is possible with mid pages,
    // try smaller value.
    //
    // Else increase pages limit.
    //
    // Time Complexity:
    // O(n * log(sum(arr)))
    //
    // Space Complexity:
    // O(1)

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        // Impossible case
        if (k > n) {
            return -1;
        }

        int low = *max_element(arr.begin(),
                               arr.end());

        int high = 0;

        for (int pages : arr) {
            high += pages;
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canAllocate(arr, k, mid)) {

                ans = mid;

                // Try smaller answer
                high = mid - 1;
            }

            else {

                // Increase pages limit
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages in books:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter number of students: ";
    cin >> k;

    Solution obj;

    int result = obj.findPages(arr, k);

    cout << "Minimum Maximum Pages: "
         << result << endl;

    return 0;
}
