/*
Problem: 84. Largest Rectangle in Histogram
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
Difficulty: Hard


Approach:
1. Find the previous smaller element index for every bar using a monotonic stack.
2. Find the next smaller element index for every bar using a monotonic stack.
3. Calculate the width and area for each histogram bar using PSE and NSE.
4. Keep track of the maximum rectangle area among all bars.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // Step 1: Find the previous smaller element index for every bar using a monotonic stack
        stack<int> st;
        vector<int> PSE(n); 
        vector<int> NSE(n); 

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Step 2: Find the next smaller element index for every bar using a monotonic stack
        st = stack<int>();

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;

        // Step 3: Calculate the width and area for each histogram bar using PSE and NSE
        // Step 4: Keep track of the maximum rectangle area among all bars
        for(int i = 0; i < n; i++) {

            int area = heights[i] * (NSE[i] - PSE[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
