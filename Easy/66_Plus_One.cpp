/*
Problem: 66. Plus One
Link: https://leetcode.com/problems/plus-one/
Difficulty: Easy


Approach:
1. Traverse the digits array from right to left while maintaining a carry.
2. Add the carry to the current digit and update the digit value.
3. Propagate the carry if the digit exceeds 9.
4. Append any remaining carry, reverse the result, and return it.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();

        vector<int> ans;

        // Step 1: Traverse the digits array from right to left while maintaining a carry
        int c=1;

        for(int i=n-1;i>=0;i--){
            
            int dg=0;

            // Step 2: Add the carry to the current digit and update the digit value
            dg=digits[i]+c;

            // Step 3: Propagate the carry if the digit exceeds 9
            if(dg>9){
                c=dg%9;
                dg=dg-(c*10);
            }
            else{
                c=0;
            }
            
            ans.push_back(dg);
        }

        // Step 4: Append any remaining carry, reverse the result, and return it
        if(c!=0){
            ans.push_back(c);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
