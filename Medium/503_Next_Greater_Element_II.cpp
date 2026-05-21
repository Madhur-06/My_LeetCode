/*
Problem: 503. Next Greater Element II
Link: https://leetcode.com/problems/next-greater-element-ii/
Difficulty: Medium


Approach:
1. Use a stack to maintain possible next greater elements in circular order.
2. Preload the stack with elements from the array to simulate circular traversal.
3. Traverse the array from right to left and remove smaller or equal elements from the stack.
4. Store the next greater element for each index and reverse the final answer vector.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n=nums.size();

        // Step 1: Use a stack to maintain possible next greater elements in circular order
        stack<int> st;

        // Step 2: Preload the stack with elements from the array to simulate circular traversal
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }

        vector<int> ans;

        // Step 3: Traverse the array from right to left and remove smaller or equal elements from the stack
        for(int i=n-1;i>=0;i--){

            while((!st.empty())&&(st.top()<=nums[i])){
                st.pop();
            }

            if(st.empty()){
                ans.push_back(-1);
                st.push(nums[i]);
                continue;
            }

            ans.push_back(st.top());
            st.push(nums[i]);
        }

        // Step 4: Store the next greater element for each index and reverse the final answer vector
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
