/*
Problem: 56. Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/
Difficulty: Medium


Approach:
1. Sort the intervals based on starting time to bring overlapping intervals together.
2. Initialize a current interval and traverse the list to check for overlaps.
3. If intervals overlap, merge them by updating the end of current interval.
4. If no overlap, store current interval and move to next, finally add last interval.


Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();

        // Step 1: Sort intervals by start time
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        vector<int>curr=intervals[0];

        // Step 2 & 3: Traverse and merge overlapping intervals
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=curr[1]){
                curr[1]=max(curr[1],intervals[i][1]);
            }
            else{
                // Step 4: No overlap, store current and move ahead
                ans.push_back(curr);
                curr=intervals[i];
            }
        }

        // Step 4: Add last interval
        ans.push_back(curr);
        return ans;
    }
};
