#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {

        // Intuition:
        // Use Dutch National Flag Algorithm.
        //
        // low  -> position for 0
        // mid  -> current element
        // high -> position for 2
        //
        // If arr[mid] == 0:
        // swap with low and move both.
        //
        // If arr[mid] == 1:
        // move mid.
        //
        // If arr[mid] == 2:
        // swap with high and decrease high.

        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {

            if (arr[mid] == 0) {

                swap(arr[low], arr[mid]);

                low++;
                mid++;
            }

            else if (arr[mid] == 1) {

                mid++;
            }

            else {

                swap(arr[mid], arr[high]);

                high--;
            }
        }
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements (0,1,2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    obj.sort012(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}