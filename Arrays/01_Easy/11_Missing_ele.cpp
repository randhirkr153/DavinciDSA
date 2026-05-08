#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Intuition:
        // Numbers are from 0 to n.
        //
        // Find sum of numbers from 0 to n
        // using formula:
        // n * (n + 1) / 2
        //
        // Subtract sum of array elements.
        // Remaining value is the missing number.

        int n = nums.size();

        int totalSum = n * (n + 1) / 2;

        int arraySum = 0;

        for (int i = 0; i < n; i++) {
            arraySum += nums[i];
        }

        return totalSum - arraySum;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Missing Number: "
         << obj.missingNumber(nums);

    return 0;
}