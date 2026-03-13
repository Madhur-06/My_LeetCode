/*
Problem: 48. Rotate Image
Link: https://leetcode.com/problems/rotate-image/
Difficulty: Medium


Approach:
1. Transpose the matrix (swap matrix[i][j] with matrix[j][i]).
2. This converts rows into columns.
3. Reverse every row of the matrix.
4. The combination of transpose + row reverse rotates the matrix by 90° clockwise.


Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int temp;
        
        // Step 1 & 2: Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Step 3 & 4: Reverse each row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (n / 2); j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
        
    }
};
