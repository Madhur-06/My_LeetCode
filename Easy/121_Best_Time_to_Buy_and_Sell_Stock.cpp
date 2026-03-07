/*
Problem: 121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: Easy


Approach:
1. Track the minimum price seen so far while traversing the array.
2. For each day, calculate the profit if stock is sold that day.
3. Update the maximum profit if current profit is greater.
4. Continue updating the minimum price for future profit calculation.

l
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& pz) {

        int n = pz.size();

        // Step 1: Initialize variables
        int p = 0, maxp = 0, m = pz[0];

        // Step 2 & 3: Calculate profit and update maximum profit
        for(int i = 1; i < n; i++){
            p = pz[i] - m;
            maxp = max(p, maxp);

            // Step 4: Update minimum price seen so far
            m = min(m, pz[i]);
        }

        maxp = max(0, maxp);
        
        return maxp;
    }
};
