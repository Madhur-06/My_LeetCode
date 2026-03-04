/*
Problem: 1021. Remove Outermost Parentheses
Link: https://leetcode.com/problems/remove-outermost-parentheses/
Difficulty: Easy


Approach:
1. Traverse the string while maintaining a counter for open parentheses.
2. When '(' appears, add it only if it is not the outermost one.
3. When ')' appears, decrease the counter and add it only if it is not closing the outermost pair.
4. This removes the outermost parentheses of every primitive substring.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans;
        int count = 0;

        // Step 1: Traverse string and track parentheses depth
        for(int i = 0; i < s.size(); i++) {

            // Step 2: Add '(' only if it is not the outermost one
            if(s[i] == '(') {
                if(count > 0)
                    ans.push_back(s[i]);
                count++;
            }
            else {
                // Step 3: Decrease depth and add ')' if not outermost
                count--;
                if(count > 0)
                    ans.push_back(s[i]);
            }
        }

        // Step 4: Result contains primitives without outer parentheses
        return ans;
    }
};
