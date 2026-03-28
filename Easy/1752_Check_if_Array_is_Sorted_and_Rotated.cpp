/*
Problem: 1752. Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty: Easy

Approach:
1. Traverse the array and count the number of break points:-
   where nums[i] > nums[(i+1)%n].
2. If break points are more than one -> array is not sorted and rotated -> return false.
3. Otherwise -> array satisfies the condition -> return true.
4. Modulo helps to compare last element with first to handle rotation.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        // Step 1: Traverse and count break points
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Step 2: If more than one break point -> invalid
        if(count > 1){
            return false;
        }

        // Step 3 & 4: Valid case (including circular check via modulo)
        return true;
    }
};
