#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {

        // Intuition:
        // Use Moore's Voting Algorithm.
        //
        // Step 1:
        // Find possible candidate.
        //
        // Step 2:
        // Count frequency of candidate.
        //
        // If frequency > n/2,
        // then candidate is majority element.
        // Otherwise return -1.

        int candidate = -1;
        int count = 0;

        // Find candidate
        for (int i = 0; i < arr.size(); i++) {

            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }

            else if (arr[i] == candidate) {
                count++;
            }

            else {
                count--;
            }
        }

        // Verify candidate
        count = 0;

        for (int num : arr) {

            if (num == candidate) {
                count++;
            }
        }

        if (count > arr.size() / 2) {
            return candidate;
        }

        return -1;
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

    cout << "Majority Element: "
         << obj.majorityElement(arr);

    return 0;
}