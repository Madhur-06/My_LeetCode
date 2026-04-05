/*
Problem: 560. Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: Medium


Approach:
1. Use a hashmap to store frequency of prefix sums.
2. Traverse the array while maintaining cumulative sum.
3. Check if (sum - k) exists in map to count valid subarrays.
4. Update hashmap with current prefix sum frequency.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
       
       int end = 0;
       int sum = 0;
        int count = 0;

        // Step 1: Initialize map with sum 0
        mp[0] = 1;

        // Step 2 & 3: Traverse and check for valid subarrays
       for(end; end < nums.size(); end++){
            sum += nums[end];

            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }

            // Step 4: Update prefix sum frequency
            mp[sum]++;
       } 
        return count;
    }
};
