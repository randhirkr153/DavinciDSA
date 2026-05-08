#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        // Intuition:
        // Keep track of largest and second largest element.
        // If current element is greater than largest:
        //      update second largest = largest
        //      update largest = current element
        //
        // Else if current element is not equal to largest
        // and greater than second largest:
        //      update second largest
        //
        // If second largest does not exist,
        // return -1.

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }

            else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }

        if (secondLargest == INT_MIN) {
            return -1;
        }

        return secondLargest;
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

    cout << "Second Largest Element: "
         << obj.getSecondLargest(arr);

    return 0;
}