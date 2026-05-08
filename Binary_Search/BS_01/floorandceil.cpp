#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        
        int floorVal = -1;
        int ceilVal = -1;

        for (int num : arr) {

            // Find Floor
            if (num <= x) {
                floorVal = max(floorVal, num);
            }

            // Find Ceil
            if (num >= x) {
                if (ceilVal == -1 || num < ceilVal) {
                    ceilVal = num;
                }
            }
        }

        return {floorVal, ceilVal};
    }
};

int main() {

    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    int x = 7;

    Solution obj;

    vector<int> ans = obj.getFloorAndCeil(x, arr);

    cout << "Floor = " << ans[0] << endl;
    cout << "Ceil = " << ans[1] << endl;

    return 0;
}