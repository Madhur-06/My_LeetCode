/*
Problem: 2149. Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
Difficulty: Medium


Approach:
1. Create a result array of the same size.
2. Maintain two pointers: one for positive index (0,2,4...) and one for negative index (1,3,5...).
3. Traverse the array and place positive numbers at even indices and negative numbers at odd indices.
4. This ensures the array alternates between positive and negative numbers.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        
        // Step 1: Create result array
        vector<int> ans(n);

        // Step 2: Initialize indices for positives and negatives
        int pos = 0, neg = 1;

        // Step 3: Place elements at correct positions
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        // Step 4: Return rearranged array
        return ans;
    }
};
