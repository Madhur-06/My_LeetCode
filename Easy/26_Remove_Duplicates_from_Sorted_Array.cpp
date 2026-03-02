/*
Problem: 26. Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Difficulty: Easy

Approach:
1. If array is empty -> return 0.
2. Use two pointers:
   - j -> points to the position of last unique element.
   - i -> traverses the array.
3. If nums[i] > nums[j], it means we found a new unique element.
   - Place it at nums[j+1]
   - Increment j
4. Return j+1 as the count of unique elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Handle empty array
        if(n == 0){
            return 0;
        }

        // Step 3: Traverse array
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[j]){
                nums[j + 1] = nums[i];
                j++;
            }
        }

        // Step 4: Return number of unique elements
        return j + 1;
    }
};
