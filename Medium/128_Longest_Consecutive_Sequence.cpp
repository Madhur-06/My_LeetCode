/*
Problem: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty: Medium


Approach:
1. Insert all elements into an unordered_set for O(1) lookups.
2. Traverse the set and identify starting points of sequences (val-1 not present).
3. For each starting point, expand the sequence forward while consecutive elements exist.
4. Track and update the maximum length of such sequences.


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n==0){
            return 0;
        }
        
        unordered_set<int> s;

        // Step 1: Insert all elements into set
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        int longest=1,len=1,cur;

        // Step 2: Traverse set and find sequence starting points
        for(int val : s){
            if(s.find(val-1)==s.end()){
                cur=val;
                len=1;

                // Step 3: Expand sequence forward
                while(s.find(cur+1)!=s.end()){
                    len++;
                    cur++;
                }

                // Step 4: Update longest sequence length
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
