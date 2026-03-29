/*
Problem: 229. Majority Element II
Link: https://leetcode.com/problems/majority-element-ii/
Difficulty: Medium


Approach:
1. Use Boyer-Moore Voting Algorithm to find up to two potential majority candidates.
2. Traverse the array and update candidates and their counts accordingly.
3. Recount occurrences of the selected candidates to verify their frequencies.
4. Add candidates to result if their count is greater than ⌊n/3⌋.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        

        int c1=0,c2=0,e1=INT_MIN,e2=INT_MAX;

        // Step 1 & 2: Find potential candidates using Boyer-Moore
        for(int i=0;i<n;i++){
            if(c1==0&&nums[i]!=e2){
                e1=nums[i];
                c1++;
            }
            else if(c2==0&&nums[i]!=e1){
                e2=nums[i];
                c2++;
            }
            else if(nums[i]==e1){
                c1++;
            }
            else if(nums[i]==e2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        c1=0;
        c2=0;

        // Step 3: Recount frequencies of candidates
        for(int i=0;i<n;i++){
            if(nums[i]==e1){
                c1++;
            }
            if(nums[i]==e2){
                c2++;
            }            
        }
        
        vector<int> ans;

        // Step 4: Check if candidates appear more than n/3 times
        if(c1>n/3){
            ans.push_back(e1);
        }
        if(c2>n/3){
            ans.push_back(e2);
        }

        return ans;
    }
};
