/*
Problem: 137. Single Number II
Link: https://leetcode.com/problems/single-number-ii/
Difficulty: Medium


Approach:
1. Use an unordered_map to store the frequency of each number.
2. Traverse the array and count occurrences of every element.
3. Iterate through the frequency map to find the element with frequency one.
4. Return the unique element found in the map.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Step 1: Use an unordered_map to store the frequency of each number
        unordered_map<int, int> m;
        
        // Step 2: Traverse the array and count occurrences of every element
        for(auto x: nums){
            m[x]++;
        }

        // Step 3: Iterate through the frequency map to find the element with frequency one
        for(auto x: m){

            // Step 4: Return the unique element found in the map
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};
