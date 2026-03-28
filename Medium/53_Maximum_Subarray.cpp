/*
Problem: 53. Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/
Difficulty: Medium


Approach:
1. Use Kadane’s Algorithm to track the running subarray sum.
2. Add each element to the current sum while traversing the array.
3. Update the maximum subarray sum whenever the current sum becomes larger.
4. If the current sum becomes negative, reset it to 0 since it cannot help future sums.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Initialize running sum and maximum sum
        int sum = 0, maxs = INT_MIN;

        // Step 2 & 3: Traverse and update maximum subarray sum
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];

            maxs = max(maxs, sum);

            // Step 4: Reset sum if it becomes negative
            if(sum < 0){
                sum = 0;
            }

        }
        return maxs;
    }
};
