/*
Problem: 907. Sum of Subarray Minimums
Link: https://leetcode.com/problems/sum-of-subarray-minimums/
Difficulty: Medium


Approach:
1. Find the previous smaller element index for every element using a monotonic stack.
2. Find the next smaller element index for every element using a monotonic stack.
3. Calculate the number of subarrays where each element acts as the minimum.
4. Add the contribution of each element to the final answer using modular arithmetic.


Time Complexity: O(n)
Space Complexity: O(n)
*/

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();

        vector<int> left(length, -1);
        vector<int> right(length, length);

        // Step 1: Find the previous smaller element index for every element using a monotonic stack
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                left[i] = stk.top();
            }

            stk.push(i);
        }

        // Step 2: Find the next smaller element index for every element using a monotonic stack
        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                right[i] = stk.top();
            }

            stk.push(i);
        }

        ll sum = 0;

        // Step 3: Calculate the number of subarrays where each element acts as the minimum
        // Step 4: Add the contribution of each element to the final answer using modular arithmetic
        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};
