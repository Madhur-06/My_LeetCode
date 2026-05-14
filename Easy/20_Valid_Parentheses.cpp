/*
Problem: 20. Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/
Difficulty: Easy


Approach:
1. Use a stack to keep track of opening brackets.
2. Push opening brackets into the stack while traversing the string.
3. For every closing bracket, check if it matches the top of the stack.
4. If all brackets are matched and the stack becomes empty, return true.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {

        // Step 1: Use a stack to keep track of opening brackets
        stack<char> st;

        for(auto val : s){

            // Step 2: Push opening brackets into the stack while traversing the string
            if(val == '(' || val == '[' || val == '{'){
                st.push(val);
            }
            else{

                // Step 3: For every closing bracket, check if it matches the top of the stack
                if(st.empty()){
                    return false;
                }

                if(val == ')'){
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(val == ']'){
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(st.top()=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        // Step 4: If all brackets are matched and the stack becomes empty, return true
        if(!st.empty()){
            return false;
        }

        return true;
    }
};
