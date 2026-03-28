/*
Problem: 118. Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle/
Difficulty: Easy


Approach:
1. Iterate through each row index and generate rows one by one.
2. For each row, compute values using nCr formula iteratively.
3. Build each row by updating the previous value using formula ans = ans*(n-r+1)/r.
4. Store each generated row into the final 2D result.


Time Complexity: O(numRows^2)
Space Complexity: O(numRows^2)
*/

class Solution {
public:
    vector<int> getRow(int n){
        
        vector<int> row;
        int ans=1;  
        row.push_back(1);

        // Step 2 & 3: Generate row using nCr iterative formula
        for(int r=1;r<=n;r++){
            ans=ans*(n-r+1)/r;
            row.push_back(ans);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        // Step 1 & 4: Generate all rows and store in result
        for(int i=0;i<numRows;i++){
            ans.push_back(getRow(i));
        }

        return ans;
    }
};
