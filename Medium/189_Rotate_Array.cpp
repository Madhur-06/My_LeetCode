/*
Problem: 189. Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Difficulty: Medium


Approach:
1. If array is empty -> return.
2. Since k can be greater than n, reduce it using:
   - k = k % n.
   - If k=0 -> return.
3. Use Reversal Algorithm:
   - Reverse entire array.
   - Reverse first k elements.
   - Reverse remaining n-k elements.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Handle edge case
        if(n == 0){
            return;
        }

        // Step 2: Reduce k
        k = k % n;

        if(k == 0){
            return;
        }

        // Step 3: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 4: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 5: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
