/*
Problem: 84. Largest Rectangle in Histogram
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
Difficulty: Hard


Approach:
1. Traverse all possible starting indices of rectangles in the histogram.
2. Extend the rectangle to every possible ending index.
3. Maintain the minimum height within the current range.
4. Calculate the area for each range and keep track of the maximum area.


Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        int maxArea = 0;
        
        // Step 1: Traverse all possible starting indices of rectangles in the histogram
        for (int i = 0; i < n; i++) {

            int minHeight = INT_MAX;

            // Step 2: Extend the rectangle to every possible ending index
            for (int j = i; j < n; j++) {

                // Step 3: Maintain the minimum height within the current range
                minHeight = min(minHeight, heights[j]);

                // Step 4: Calculate the area for each range and keep track of the maximum area
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        
        return maxArea;
    }
};
