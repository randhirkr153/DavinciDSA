#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Merge function
    long long merge(vector<int>& arr,
                    int low,
                    int mid,
                    int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long inversionCount = 0;

        // Merge two sorted halves
        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {

                temp.push_back(arr[left]);
                left++;
            }

            else {

                temp.push_back(arr[right]);

                // All remaining elements
                // in left half are greater
                inversionCount += (mid - left + 1);

                right++;
            }
        }

        // Remaining left half
        while (left <= mid) {

            temp.push_back(arr[left]);
            left++;
        }

        // Remaining right half
        while (right <= high) {

            temp.push_back(arr[right]);
            right++;
        }

        // Copy back to original array
        for (int i = low; i <= high; i++) {

            arr[i] = temp[i - low];
        }

        return inversionCount;
    }

    // Merge Sort function
    long long mergeSort(vector<int>& arr,
                        int low,
                        int high) {

        long long inversionCount = 0;

        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;

        // Left half
        inversionCount += mergeSort(arr, low, mid);

        // Right half
        inversionCount += mergeSort(arr, mid + 1, high);

        // Merge and count inversions
        inversionCount += merge(arr, low, mid, high);

        return inversionCount;
    }

    long long inversionCount(vector<int>& arr) {

        // Intuition:
        // We use Merge Sort.
        //
        // During merging:
        // if left element > right element,
        // then all remaining elements
        // in left half will also form inversions.
        //
        // Count = (mid - left + 1)
        //
        // Time Complexity : O(n log n)
        // Space Complexity: O(n)

        int n = arr.size();

        return mergeSort(arr, 0, n - 1);
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    long long result =
        obj.inversionCount(arr);

    cout << "\nInversion Count = "
         << result << endl;

    return 0;
}