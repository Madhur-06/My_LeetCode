/*
Problem: 136. Single Number
Link: https://leetcode.com/problems/single-number/
Difficulty: Easy


Approach:
1. Initialize XOR with the first element of the array.
2. Traverse the array and keep applying XOR with each element.
3. Use property that a^a = 0 and a^0 = a to cancel duplicate elements.
4. The remaining value after all XOR operations is the single number.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n=nums.size();

        // Step 1: Initialize XOR with first element
        int xor_val=nums[0];

        // Step 2 & 3: Apply XOR to cancel duplicates
        for(int i=1;i<n;i++){
            xor_val=xor_val^nums[i];
        }

        // Step 4: Remaining value is the answer
        return xor_val;
    }
};
