/*
Problem: 169. Majority Element
Link: https://leetcode.com/problems/majority-element/
Difficulty: Easy


Approach:
1. Use Boyer–Moore Voting Algorithm to find the majority candidate.
2. If count becomes 0, choose the current element as the new candidate.
3. Increase count if the current element equals the candidate, otherwise decrease it.
4. The remaining candidate at the end is the majority element.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        // Step 1: Initialize candidate and counter
        int el, count = 0;

        // Step 2 & 3: Apply Boyer–Moore Voting
        for(int i = 0; i < n; i++){
            if(count == 0){
                el = nums[i];
                count++;
            }
            else{
                if(nums[i] == el){
                    count++;
                }
                else{
                    count--;
                }
            }
        }

        // Step 4: Candidate is the majority element
        return el;
    }
};
