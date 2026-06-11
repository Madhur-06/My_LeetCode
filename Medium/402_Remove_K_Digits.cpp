/*
Problem: 402. Remove K Digits
Link: https://leetcode.com/problems/remove-k-digits/
Difficulty: Medium


Approach:
1. Use a monotonic increasing stack to build the smallest possible number.
2. Remove larger previous digits while k is greater than zero.
3. Remove any remaining digits from the end if k is still left.
4. Construct the result, remove leading zeros, and return the final number.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n=num.size();

        if(k==n){
            return "0";
        }

        // Step 1: Use a monotonic increasing stack to build the smallest possible number
        stack<char> st;
        string ans;

        for(int i=0;i<n;i++){

            // Step 2: Remove larger previous digits while k is greater than zero
            while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // Step 3: Remove any remaining digits from the end if k is still left
        while(k>0){
            st.pop();
            k--;
        }

        // Step 4: Construct the result, remove leading zeros, and return the final number
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int i = 0;

        while(i<ans.size() && ans[i]=='0'){
            i++;
        }

        ans=ans.substr(i);

        if(ans.empty()){
            return "0";
        }

        return ans;
    }
};
