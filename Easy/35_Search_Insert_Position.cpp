/*
Problem: 35. Search Insert Position
Link: https://leetcode.com/problems/search-insert-position/
Difficulty: Easy


Approach:
1. Use Binary Search with two pointers: start (st) and end (ed).
2. Find the middle element and compare it with the target.
3. If target is greater, search in the right half; if smaller, search in the left half.
4. If not found, return the index where the target should be inserted.


Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();

        // Step 1: Initialize binary search pointers
        int st = 0, ed = n - 1, mid;

        // Step 2 & 3: Perform binary search
        while(st <= ed){
            mid = st + (ed - st) / 2;

            if(target > nums[mid]){
                st = mid + 1;
            }
            else if(target < nums[mid]){
                ed = mid - 1;
            }
            else{
                return mid;
            }
        }

        // Step 4: Return correct insert position
        if(target > nums[mid]){
            return mid + 1;
        }
        return mid;
    }
};
