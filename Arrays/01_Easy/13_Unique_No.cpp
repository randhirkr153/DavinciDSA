#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnique(vector<int>& arr) {

        // Intuition:
        // XOR of same numbers becomes 0.
        //
        // Example:
        // 5 ^ 5 = 0
        //
        // XOR of 0 with a number gives the number itself.
        //
        // So by XOR-ing all elements,
        // duplicate numbers cancel out
        // and only unique number remains.

        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            ans = ans ^ arr[i];
        }

        return ans;
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

    cout << "Unique Number: "
         << obj.findUnique(arr);

    return 0;
}