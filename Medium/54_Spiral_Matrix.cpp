/*
Problem: 54. Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/
Difficulty: Medium


Approach:
1. Traverse the matrix layer by layer using four boundaries: top, bottom, left, right.
2. Traverse from left → right, then top → bottom, then right → left, then bottom → top.
3. After each traversal, shrink the boundaries inward.
4. Continue until all elements are added to the result.


Time Complexity: O(m * n)
Space Complexity: O(1) (excluding output array)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int iter = 0;

        // Step 1, 2, 3 & 4: Traverse layer by layer
        while(ans.size() < n * m){
            int top = 0 + iter, down = m - 1 - iter;
            int left = 0 + iter, right = n - 1 - iter;

            for(int i = left; i <= right && ans.size() < n * m; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= down && ans.size() < n * m; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            for(int i = right; i >= left && ans.size() < n * m; i--){
                ans.push_back(matrix[down][i]);
            }
            down--;
            
            for(int i = down; i >= top && ans.size() < n * m; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;

            iter++;
        }
        return ans;
    }
};
