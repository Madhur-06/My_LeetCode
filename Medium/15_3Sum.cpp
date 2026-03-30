/*
Problem: 15. 3Sum
Link: https://leetcode.com/problems/3sum/
Difficulty: Medium


Approach:
1. Sort the array to enable two-pointer technique and handle duplicates easily.
2. Fix one element and use two pointers (j, k) to find pairs with sum equal to target.
3. If a valid triplet is found, store it in a set to avoid duplicates.
4. Transfer all unique triplets from set to result vector and return.


Time Complexity: O(n^2 log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<vector<int>> ans;

        // Step 2 & 3: Fix element and find pairs using two pointers
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        // Step 4: Move unique triplets from set to result
        for(auto triplets : s)
            ans.push_back(triplets);

        return ans;
    }
};
