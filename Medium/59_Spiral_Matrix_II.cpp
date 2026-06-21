/*
Problem: 59. Spiral Matrix II
Link: https://leetcode.com/problems/spiral-matrix-ii/
Difficulty: Medium


Approach:
1. Initialize a matrix and four boundaries to represent the current layer.
2. Fill the top row and right column while moving clockwise.
3. Fill the bottom row and left column when valid boundaries remain.
4. Continue shrinking the boundaries until all numbers are placed.


Time Complexity: O(n²)
Space Complexity: O(1) [excluding output matrix]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        // Step 1: Initialize a matrix and four boundaries to represent the current layer
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int num = 1;

        // Step 4: Continue shrinking the boundaries until all numbers are placed
        while (left <= right && top <= bottom) {

            // Step 2: Fill the top row and right column while moving clockwise
            for (int j = left; j <= right; j++) {
                matrix[top][j] = num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;
    
            // Step 3: Fill the bottom row and left column when valid boundaries remain
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j] = num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};
