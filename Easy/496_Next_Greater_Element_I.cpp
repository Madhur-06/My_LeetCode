/*
Problem: 496. Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
Difficulty: Easy


Approach:
1. Traverse nums2 from right to left using a monotonic decreasing stack.
2. Remove all smaller or equal elements from the stack for each current element.
3. Store the next greater element of every number in an unordered_map.
4. Build the answer for nums1 using the stored next greater elements.


Time Complexity: O(n + m)
Space Complexity: O(m)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();

        // Step 3: Store the next greater element of every number in an unordered_map
        unordered_map<int,int> mp;

        // Step 1: Traverse nums2 from right to left using a monotonic decreasing stack
        stack<int> st;

        for(int i=m-1;i>=0;i--){

            // Step 2: Remove all smaller or equal elements from the stack for each current element
            while((!st.empty())&&st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
                continue;
            }

            mp[nums2[i]]=st.top();
            st.push(nums2[i]);

        }

        vector<int> ans;

        // Step 4: Build the answer for nums1 using the stored next greater elements
        for(int i=0;i<n;i++){
            
            ans.push_back(mp[nums1[i]]);

        }

        return ans;
    }
};
