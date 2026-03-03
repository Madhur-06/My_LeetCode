/*
Problem: 283. Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/
Difficulty: Easy


Approach:
1. Find the first zero element and store its index.
2. If no zero is found, return (already valid).
3. Traverse remaining array and swap non-zero elements with zero position.
4. This keeps relative order and moves all zeros to the end.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Find first zero index
        int j = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        // Step 2: If no zero found → return
        if(j == -1){
            return;
        }

        // Step 3: Swap non-zero elements with zero position
        for(int i = j + 1; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

        // Step 4: Zeros are moved to end maintaining order
        return;
    }
};
