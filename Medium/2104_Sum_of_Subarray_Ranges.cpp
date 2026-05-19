/*
Problem: 2104. Sum of Subarray Ranges
Link: https://leetcode.com/problems/sum-of-subarray-ranges/
Difficulty: Medium

Approach:
1. Traverse all possible starting indices of subarrays.
2. Initialize the maximum and minimum values for each starting index.
3. Extend the subarray one element at a time while updating maximum and minimum values.
4. Add the difference between maximum and minimum values to the final answer.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n=nums.size();
        long long res=0;

        // Step 1: Traverse all possible starting indices of subarrays
        for(int i=0;i<n-1;i++){

            // Step 2: Initialize the maximum and minimum values for each starting index
            int maxi=nums[i], mini=nums[i];

            // Step 3: Extend the subarray one element at a time while updating maximum and minimum values
            for(int j=i+1;j<n;j++){

                if(nums[j]>maxi)
                    maxi=nums[j];

                else if(nums[j]<mini)
                    mini=nums[j];

                // Step 4: Add the difference between maximum and minimum values to the final answer
                res+=maxi-mini;
            }
        }

        return res;
    }
};
