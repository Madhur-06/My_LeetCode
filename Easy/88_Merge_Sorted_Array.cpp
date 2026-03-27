/*
Problem: 88. Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
Difficulty: Easy


Approach:
1. Copy all elements of nums2 into the remaining positions of nums1.
2. After copying, nums1 contains all elements from both arrays.
3. Sort nums1 to arrange elements in non-decreasing order.
4. The final sorted nums1 is the merged array.


Time Complexity: O((m+n) log(m+n))
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Step 1: Copy nums2 elements into nums1
        for (int j = 0, i = m; j < n; j++){
            nums1[i] = nums2[j];
            i++;
        }

        // Step 2 & 3: Sort the merged array
        sort(nums1.begin(), nums1.end());

        // Step 4: nums1 now contains merged sorted elements
    }
};
