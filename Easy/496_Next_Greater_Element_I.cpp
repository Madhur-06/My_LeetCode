/*
Problem: 496. Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
Difficulty: Easy


Approach:
1. Traverse nums2 from right to left using a monotonic decreasing stack.
2. Find the next greater element for every element in nums2 and store it.
3. Store the index of each element of nums2 in an unordered_map.
4. Use the stored indices and next greater values to build the final answer for nums1.


Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();

        // Step 3: Store the index of each element of nums2 in an unordered_map
        unordered_map<int,int> mp;

        // Step 1: Traverse nums2 from right to left using a monotonic decreasing stack
        stack<int> st;

        vector<int> vec;

        for(int i=m-1;i>=0;i--){

            mp[nums2[i]]=i;

            while((!st.empty())&&st.top()<=nums2[i]){
                st.pop();
            }

            // Step 2: Find the next greater element for every element in nums2 and store it
            if(st.empty()){
                vec.push_back(-1);
                st.push(nums2[i]);
                continue;
            }

            vec.push_back(st.top());
            st.push(nums2[i]);

        }

        vector<int> ans;

        // Step 4: Use the stored indices and next greater values to build the final answer for nums1
        for(int i=0;i<n;i++){
            
            int id=mp[nums1[i]];
            ans.push_back(vec[m-id-1]);

        }

        return ans;
    }
};
