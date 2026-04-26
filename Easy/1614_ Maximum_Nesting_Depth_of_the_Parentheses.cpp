/*
Problem: 1614. Maximum Nesting Depth of the Parentheses
Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
Difficulty: Easy


Approach:
1. Traverse the string and track current depth using a counter.
2. Increment depth when encountering '('.
3. Decrement depth when encountering ')'.
4. Keep updating maximum depth encountered.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {

        int n=s.size();

        int c=0,mc=0;

        // Step 1, 2 & 3: Traverse and update depth
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
                mc=max(c,mc);
            }
            else if(s[i]==')'){
                c--;
            }
            else{
                continue;
            }
        }   

        // Step 4: Return maximum depth
        return mc;
    }
};
