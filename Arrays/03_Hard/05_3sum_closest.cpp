#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& arr, int target) {

        // Intuition:
        // We sort the array first.
        //
        // Then for every element arr[i],
        // we use two pointers:
        //
        // left  -> i + 1
        // right -> n - 1
        //
        // Calculate current sum:
        // sum = arr[i] + arr[left] + arr[right]
        //
        // If sum is closer to target,
        // update answer.
        //
        // If multiple sums have same distance,
        // return maximum sum.
        //
        // Time Complexity : O(n^2)
        // Space Complexity: O(1)

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int closestSum = INT_MAX;

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = arr[i] + arr[left] + arr[right];

                // Update closest sum
                if (abs(target - sum) < abs(target - closestSum)) {

                    closestSum = sum;
                }

                // If same distance, take maximum sum
                else if (abs(target - sum) == abs(target - closestSum)) {

                    closestSum = max(closestSum, sum);
                }

                // Move pointers
                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    return sum;
                }
            }
        }

        return closestSum;
    }
};

int main() {

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    int result = obj.threeSumClosest(arr, target);

    cout << "Closest Sum = " << result << endl;

    return 0;
}