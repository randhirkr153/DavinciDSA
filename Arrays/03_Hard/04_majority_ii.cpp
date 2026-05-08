// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {

//         // Intuition:
//         // Using Boyer-Moore Voting Algorithm
//         //
//         // Observation:
//         // At most 2 elements can appear
//         // more than n/3 times.
//         //
//         // Why?
//         // Because if there were 3 such elements,
//         // total count would exceed n.
//         //
//         // So we keep:
//         // candidate1, count1
//         // candidate2, count2
//         //
//         // Step 1:
//         // Find possible candidates
//         //
//         // Step 2:
//         // Verify their actual frequency
//         //
//         // Time Complexity : O(n)
//         // Space Complexity: O(1)

//         int candidate1 = 0, candidate2 = 1;
//         int count1 = 0, count2 = 0;

//         // Find candidates
//         for (int num : nums) {

//             if (num == candidate1) {
//                 count1++;
//             }

//             else if (num == candidate2) {
//                 count2++;
//             }

//             else if (count1 == 0) {
//                 candidate1 = num;
//                 count1 = 1;
//             }

//             else if (count2 == 0) {
//                 candidate2 = num;
//                 count2 = 1;
//             }

//             else {
//                 count1--;
//                 count2--;
//             }
//         }

//         // Verify candidates
//         count1 = 0;
//         count2 = 0;

//         for (int num : nums) {

//             if (num == candidate1)
//                 count1++;

//             else if (num == candidate2)
//                 count2++;
//         }

//         vector<int> ans;

//         int n = nums.size();

//         if (count1 > n / 3)
//             ans.push_back(candidate1);

//         if (count2 > n / 3)
//             ans.push_back(candidate2);

//         return ans;
//     }
// };