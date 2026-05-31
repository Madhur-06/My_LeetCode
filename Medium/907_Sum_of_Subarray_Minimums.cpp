/*
Problem: 907. Sum of Subarray Minimums
Link: https://leetcode.com/problems/sum-of-subarray-minimums/
Difficulty: Medium


Approach:
1. Find the previous less element index for every element using a monotonic stack.
2. Find the next less element index for every element using a monotonic stack.
3. Calculate the number of subarrays where each element acts as the minimum.
4. Add the contribution of each element to the total sum using modular arithmetic.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> ple(n); 
        vector<int> nle(n); 

        // Step 1: Find the previous less element index for every element using a monotonic stack
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ple[i] = -1;
            } 
            else {
                ple[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        
        // Step 2: Find the next less element index for every element using a monotonic stack
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nle[i] = n;
            } 
            else {
                nle[i] = st.top();
            }

            st.push(i);
        }

        long long totalSum = 0;

        // Step 3: Calculate the number of subarrays where each element acts as the minimum
        // Step 4: Add the contribution of each element to the total sum using modular arithmetic
        for (int i = 0; i < n; i++) {

            long long leftCount = i - ple[i];
            long long rightCount = nle[i] - i;

            long long contribution =
                (1LL * arr[i] * leftCount * rightCount) % mod;

            totalSum = (totalSum + contribution) % mod;
        }

        return totalSum;
    }
};
