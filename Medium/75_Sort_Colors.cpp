/*
Problem: 75. Sort Colors
Link: https://leetcode.com/problems/sort-colors/
Difficulty: Medium


Approach:
1. Use the Dutch National Flag Algo to sort the array.
2. Traverse the array using mid pointer.
3. Swap elements based on value (0 → front, 2 → back, 1 → middle).
4. Continue until mid crosses high to complete sorting.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low=0,mid=0,high=n-1;

        // Step 2,3 & 4: Traverse and rearrange using three pointers
        while(mid<=high){

            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                nums[mid]=nums[low];
                nums[low]=0;
                mid++;
                low++;
            }
            else{
                nums[mid]=nums[high];
                nums[high]=2;
                high--;
            }

        }

        return;
    }
};
