/*
Problem: 268. Missing Number
Link: https://leetcode.com/problems/missing-number/
Difficulty: Easy


Approach:
1. Initialize result variable to store XOR of indices and array elements.
2. Traverse the array and XOR both (i+1) and nums[i] with result.
3. Use XOR property where equal numbers cancel out, leaving the missing number.
4. Return the final result.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int res=0;

        // Step 1, 2 & 3: XOR indices and elements to find missing number
        for(int i=0;i<n;i++){
            res^=(i+1)^nums[i];
        }
        
        // Step 4: Return result
        return res;
    }
};
