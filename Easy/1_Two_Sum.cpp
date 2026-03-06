/*
Problem: 1. Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy


Approach:
1. Store each element and its index in an unordered_map.
2. Traverse the array and compute the required complement (target - nums[i]).
3. Check if the complement exists in the map and is not the same index.
4. If found, return the indices of the two numbers.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        int n = nums.size();

        // Step 1: Store numbers with their indices
        unordered_map<int,int> m;

        for(int i = 0; i < n; i++){
            m[nums[i]] = i;
        }

        // Step 2 & 3: Find complement and check in map
        for(int i = 0; i < n; i++){
            if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i){
                ans.push_back(i);
                ans.push_back(m[target - nums[i]]);
                return ans;
            }
        }

        // Step 4: Return empty if no pair found
        return {};
    }
};
