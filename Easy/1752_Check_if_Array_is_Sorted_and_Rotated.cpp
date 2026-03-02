/*
Problem: 1752. Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty: Easy


Approach:
1. Traverse the array and find the position of break point:-
   where nums[i] > nums[i+1].
2. If there is no break point -> array is already sorted -> return true.
3. Ensure last element <= first element
4. Ensure the remaining portion after the break is sorted


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int n=nums.size();

        // Step 1: Find first decreasing pair
        int brk=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                brk=i+1;
                break;
            }
        }

        // Step 2: If no break point → already sorted
        if(brk==-1){
            return true;
        }

        // Step 3: Last element must not be greater than first
        if(nums[n-1]>nums[0]){
            return false;
        }

        // Step 4: Ensure remaining part is sorted
        for(int i=brk;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }

        return true;
    }
};
