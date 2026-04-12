/*
Problem: 493. Reverse Pairs
Link: https://leetcode.com/problems/reverse-pairs/
Difficulty: Hard


Approach:
1. Use merge sort to divide the array into smaller subarrays.
2. During merge step, count reverse pairs where nums[i] > 2 * nums[j].
3. Merge the two sorted halves into a temporary array.
4. Accumulate and return the total count of reverse pairs.


Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){

        // Step 2: Count reverse pairs
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }

        // Step 3: Merge two sorted halves
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;

        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }

        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){

        // Step 1: Divide array recursively
        if(low >= high){
            return;
        }

        int mid = (low + high) >> 1;

        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);

        // Step 2 & 3: Count pairs and merge
        merge(nums, low, mid, high, reversePairsCount);
    }

public:
    int reversePairs(vector<int>& nums) {

        int reversePairsCount = 0;

        // Step 4: Return total count after merge sort
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);

        return reversePairsCount;
    }
};
