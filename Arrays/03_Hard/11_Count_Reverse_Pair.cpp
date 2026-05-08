#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Merge two sorted halves
    void merge(vector<int>& arr,
               int low,
               int mid,
               int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {

                temp.push_back(arr[left]);
                left++;
            }

            else {

                temp.push_back(arr[right]);
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

        // Copy back
        for (int i = low; i <= high; i++) {

            arr[i] = temp[i - low];
        }
    }

    // Count reverse pairs
    int countPairs(vector<int>& arr,
                   int low,
                   int mid,
                   int high) {

        int count = 0;

        int right = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (right <= high &&
                   (long long)arr[i] >
                   2LL * arr[right]) {

                right++;
            }

            count += (right - (mid + 1));
        }

        return count;
    }

    // Merge Sort
    int mergeSort(vector<int>& arr,
                  int low,
                  int high) {

        int count = 0;

        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;

        // Left half
        count += mergeSort(arr, low, mid);

        // Right half
        count += mergeSort(arr, mid + 1, high);

        // Count reverse pairs
        count += countPairs(arr, low, mid, high);

        // Merge sorted halves
        merge(arr, low, mid, high);

        return count;
    }

    int countRevPairs(vector<int>& arr) {

        // Intuition:
        // We use Merge Sort.
        //
        // Before merging two sorted halves,
        // count pairs:
        //
        // arr[i] > 2 * arr[j]
        //
        // Since halves are sorted,
        // we can count efficiently
        // using two pointers.
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

    int result = obj.countRevPairs(arr);

    cout << "\nReverse Pairs Count = "
         << result << endl;

    return 0;
}