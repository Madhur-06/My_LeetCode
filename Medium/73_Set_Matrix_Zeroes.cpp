/*
Problem: 73. Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
Difficulty: Medium


Approach:
1. Check if the first row or first column originally contains any zero.
2. Use the first row and first column as markers to indicate which rows and columns should become zero.
3. Traverse the matrix again and set elements to zero based on the markers.
4. Finally, update the first row and first column if they initially contained zeros.


Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Check if first row or first column has zero
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 2: Mark rows and columns using first row and column
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: Set elements to zero based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Update first row and first column if needed
        if(firstRowZero) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(firstColZero) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
