/*
Problem: 18. 4Sum
Link: https://leetcode.com/problems/4sum/
Difficulty: Medium


Approach:
1. Sort the array to apply two-pointer technique and handle duplicates.
2. Fix two elements (i, j) and skip duplicates to avoid repeated quadruplets.
3. Use two pointers (left, right) to find remaining two elements forming target sum.
4. Store valid quadruplets and skip duplicates while moving pointers.


Time Complexity: O(n^3)
Space Complexity: O(1) (excluding result)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        // Step 1 & 2: Fix first two elements and skip duplicates
        for (int i = 0; i < ssize(nums); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < ssize(nums); j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = ssize(nums) - 1;

                // Step 3 & 4: Two-pointer search for remaining elements
                while (left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right && nums[right] == nums[right + 1]) right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    }

                    else if (sum > target) right--;
                    else left++;
                }
            }
        }

        return res;
    }
};
