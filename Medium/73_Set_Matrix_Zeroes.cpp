/*
Problem: 73. Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
Difficulty: Medium


Approach:
1. Check if first row and first column initially contain any zeroes and store in flags.
2. Use first row and column as markers to indicate which rows and columns should be zeroed.
3. Traverse matrix again and set elements to zero based on markers.
4. Finally, update first row and column using the stored flags.


Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        int zr=0;

        // Step 1: Check if first row has zero
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                zr=1;
                break;
            }
        }

        int zc=0;

        // Step 1: Check if first column has zero
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                zc=1;
                break;
            }
        }

        // Step 2: Mark rows and columns using first row & column
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        // Step 3: Set matrix elements to zero based on markers
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // Step 4: Update first row if needed
        if(zr==1){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }

        // Step 4: Update first column if needed
        if(zc==1){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
