/*
Problem: 31. Next Permutation
Link: https://leetcode.com/problems/next-permutation/
Difficulty: Medium


Approach:
1. Find the first decreasing element from the right (pivot index).
2. If no such element exists, reverse the entire array.
3. Find the next greater element than pivot from the right and swap.
4. Reverse the suffix after pivot to get next permutation.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int pt=-1;

        // Step 1: Find pivot (first decreasing element from right)
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pt=i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if(pt==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        // Step 3: Find next greater element and swap
        for(int i=n-1;i>pt;i--){
            if(nums[i]>nums[pt]){
                swap(nums[i], nums[pt]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin()+pt+1,nums.end());
        
        return;
    }
};
