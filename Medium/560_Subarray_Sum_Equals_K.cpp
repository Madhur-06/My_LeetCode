/*
Problem: 560. Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: Medium


Approach:
1. Compute prefix sum array to store cumulative sums.
2. Traverse prefix array and check if prefix[i] equals k.
3. Use hashmap to find previous prefix sums equal to (prefix[i] - k).
4. Update hashmap with current prefix sum frequency.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        
        int prefix[n]; 
        
        // Step 1: Build prefix sum array
        prefix[0] = arr[0]; 
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; 
        
        int ans = 0; 
        
        // Step 2, 3 & 4: Traverse and count subarrays
        for(int i = 0; i < n; i++) 
        {
            if(prefix[i] == k) 
                ans++;
            
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; 
            }
            
            mp[prefix[i]]++; 
        }
        
        return ans; 
    }
};
