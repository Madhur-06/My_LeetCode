/*
Problem: 75. Sort Colors
Link: https://leetcode.com/problems/sort-colors/
Difficulty: Medium


Approach:
1. Traverse the array and count the number of 0s, 1s, and 2s.
2. Compute the ending index range for each number using cumulative counts.
3. Traverse the array again and fill 0s, then 1s, then 2s according to counts.
4. This rearranges the array in sorted order.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        // Step 1: Count number of 0s, 1s and 2s
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                c0++;
            }
            else if(nums[i] == 1){
                c1++;
            }
            else{
                c2++;
            }
        }

        // Step 2: Convert counts into index ranges
        c1 = c1 + c0;
        c2 = c2 + c1;

        // Step 3: Fill array based on calculated ranges
        for(int i = 0; i < n; i++){
            if(i < c0){
                nums[i] = 0;
            }
            else if(i < c1){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }

        // Step 4: Array becomes sorted with 0s, then 1s, then 2s
    }
};
