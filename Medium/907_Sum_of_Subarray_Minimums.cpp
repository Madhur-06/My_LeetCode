/*
Problem: 907. Sum of Subarray Minimums
Link: https://leetcode.com/problems/sum-of-subarray-minimums/
Difficulty: Medium


Approach:
1. Find the distance to the next less element for every index using a monotonic stack.
2. Find the distance to the previous less element for every index using a monotonic stack.
3. Calculate the number of subarrays where each element is the minimum using both distances.
4. Add the contribution of each element to the answer using modular arithmetic.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {

        int n=nums.size();

        vector<int> nle;
        vector<int> ple;

        // Step 1: Find the distance to the next less element for every index using a monotonic stack
        nle.push_back(1);

        stack<int> nle_st;
        nle_st.push(n-1);

        for(int i=n-2;i>=0;i--){
            
            while(!nle_st.empty() && nums[i]<=nums[nle_st.top()]){
                nle_st.pop();
            }
            
            if(nle_st.empty()){
                nle.push_back(n-i);
                nle_st.push(i);
                continue;
            }

            nle.push_back(nle_st.top()-i);
            nle_st.push(i);
        }

        reverse(nle.begin(),nle.end());

        // Step 2: Find the distance to the previous less element for every index using a monotonic stack
        ple.push_back(1);

        stack<int> ple_st;
        ple_st.push(0);

        for(int i=1;i<n;i++){
            
            while(!ple_st.empty() && nums[i]<nums[ple_st.top()]){
                ple_st.pop();
            }
            
            if(ple_st.empty()){
                ple.push_back(i+1);
                ple_st.push(i);
                continue;
            }

            ple.push_back(i-ple_st.top());
            ple_st.push(i);
        }

        long long ans=0;

        // Step 3: Calculate the number of subarrays where each element is the minimum using both distances
        // Step 4: Add the contribution of each element to the answer using modular arithmetic
        for(int i=0;i<n;i++){
            ans=(ans+((long long)nums[i]*nle[i]*ple[i]))%(1000000007);
        }

        return int(ans);
    }
};
