#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& arr, int target) {

        // Intuition:
        // Sort the array first.
        //
        // Fix first two elements:
        // arr[i] and arr[j]
        //
        // Then use two pointers:
        // left  -> j + 1
        // right -> n - 1
        //
        // Find quadruples such that:
        // arr[i] + arr[j] + arr[left] + arr[right] = target
        //
        // Skip duplicates to avoid
        // repeated quadruples.
        //
        // Time Complexity : O(n^3)
        // Space Complexity: O(1)
        // (excluding answer array)

        vector<vector<int>> ans;

        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first element
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second element
                if (j > i + 1 && arr[j] == arr[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum =
                        (long long)arr[i] +
                        arr[j] +
                        arr[left] +
                        arr[right];

                    // Found valid quadruple
                    if (sum == target) {

                        ans.push_back({
                            arr[i],
                            arr[j],
                            arr[left],
                            arr[right]
                        });

                        left++;
                        right--;

                        // Skip duplicate left values
                        while (left < right &&
                               arr[left] == arr[left - 1]) {
                            left++;
                        }

                        // Skip duplicate right values
                        while (left < right &&
                               arr[right] == arr[right + 1]) {
                            right--;
                        }
                    }

                    // Need bigger sum
                    else if (sum < target) {
                        left++;
                    }

                    // Need smaller sum
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
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

    vector<vector<int>> result =
        obj.fourSum(arr, target);

    cout << "\nQuadruples are:\n";

    if (result.empty()) {
        cout << "No quadruples found";
    }
    else {

        for (auto quad : result) {

            cout << "[ ";

            for (int x : quad) {
                cout << x << " ";
            }

            cout << "]\n";
        }
    }

    return 0;
}