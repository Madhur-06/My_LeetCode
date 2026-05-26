/*
Problem: 85. Maximal Rectangle
Link: https://leetcode.com/problems/maximal-rectangle/
Difficulty: Hard


Approach:
1. Build a histogram for each row by counting consecutive 1s in every column.
2. Use a monotonic stack to calculate the largest rectangle area in the histogram.
3. Compute the width and area whenever a smaller height is encountered.
4. Update the maximum rectangle area for every row histogram.


Time Complexity: O(m * n)
Space Complexity: O(n)
*/

class Solution {
public:
    int area(vector<int>& heights) {

        int n = heights.size();

        // Step 2: Use a monotonic stack to calculate the largest rectangle area in the histogram
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int h = (i == n) ? 0 : heights[i];

            // Step 3: Compute the width and area whenever a smaller height is encountered
            while (!st.empty() && h < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();

        if (m == 0)
            return 0;

        int n = matrix[0].size();

        // Step 1: Build a histogram for each row by counting consecutive 1s in every column
        vector<int> hist(n, 0);

        int ans = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            }

            // Step 4: Update the maximum rectangle area for every row histogram
            ans = max(ans, area(hist));
        }

        return ans;
    }
};
