/*
Problem: 189. Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Difficulty: Medium


Approach:
1. Handle edge cases and reduce k using modulo to avoid unnecessary rotations.
2. Reverse the entire array to prepare for correct positioning.
3. Reverse the first k elements to place them in correct rotated order.
4. Reverse the remaining elements to complete the rotation.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Step 1: Handle edge cases and normalize k
        if(n == 0 || k == 0){
            return;
        }

        // Step 2: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 3: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 4: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
