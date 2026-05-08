#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool cmp(pair<int, int> &a, pair<int, int> &b) {

        // If frequency same,
        // smaller number first
        if(a.second == b.second) {
            return a.first < b.first;
        }

        // Higher frequency first
        return a.second > b.second;
    }

    vector<int> sortByFreq(vector<int>& arr) {

        // Intuition:
        // Step 1:
        // Count frequency of each element
        //
        // Step 2:
        // Store element and frequency in vector
        //
        // Step 3:
        // Sort based on:
        // 1. Higher frequency first
        // 2. Smaller number first if frequency same
        //
        // Step 4:
        // Put elements in answer according to frequency

        unordered_map<int, int> freq;

        // Count frequency
        for(int num : arr) {
            freq[num]++;
        }

        vector<pair<int, int>> temp;

        // Store {element, frequency}
        for(auto it : freq) {
            temp.push_back({it.first, it.second});
        }

        // Sort using custom comparator
        sort(temp.begin(), temp.end(), cmp);

        vector<int> ans;

        // Build answer
        for(auto it : temp) {

            int num = it.first;
            int count = it.second;

            while(count--) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = obj.sortByFreq(arr);

    cout << "Sorted Array: ";

    for(int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}