/*
Problem: 560. Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: Medium


Approach:
1. Use a hashmap to store frequency of prefix sums and initialize with 0.
2. Traverse the array while maintaining cumulative sum.
3. Check if (sum - k) exists in map to count valid subarrays.
4. Update hashmap with current prefix sum frequency.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();

        unordered_map<int,int> mp;

        // Step 1: Initialize map with sum 0
        mp[0]=1;

        int sum=0,ans=0;

        // Step 2 & 3: Traverse and check for valid subarrays
        for(int i=0;i<n;i++){
            
            sum=sum+arr[i];

            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }

            // Step 4: Update prefix sum frequency
            mp[sum]++;
        } 

        return ans;
    }
};
