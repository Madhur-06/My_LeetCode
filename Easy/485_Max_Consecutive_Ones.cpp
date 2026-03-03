/*
Problem: 485. Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/
Difficulty: Easy


Approach:
1. Traverse the array while counting consecutive 1s.
2. If a 0 is encountered, update maximum count and reset counter.
3. Continue counting for remaining elements.
4. After loop, update maximum once more to handle ending 1s.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Initialize counters
        int count = 0, mcount = 0;

        // Step 2 & 3: Traverse and count consecutive 1s
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                mcount = max(mcount, count);
                count = 0;
            }
            else{
                count++;
            }
        }

        // Step 4: Final update for ending 1s
        mcount = max(mcount, count);

        return mcount;
    }
};
