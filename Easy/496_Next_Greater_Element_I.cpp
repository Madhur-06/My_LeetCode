/*
Problem: 496. Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
Difficulty: Easy


Approach:
1. Store each element of nums2 with its index in an unordered_map.
2. Traverse nums1 and find the index of each element in nums2.
3. Search towards the right side of nums2 to find the next greater element.
4. Store the next greater element in the answer vector or keep -1 if not found.


Time Complexity: O(m * n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums2.size();
        int m=nums1.size();

        // Step 1: Store each element of nums2 with its index in an unordered_map
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        vector<int> ans(m,-1);

        // Step 2: Traverse nums1 and find the index of each element in nums2
        for(int i=0;i<m;i++){
            
            int id=mp[nums1[i]];

            // Step 3: Search towards the right side of nums2 to find the next greater element
            for(int j=id+1;j<n;j++){
                if(nums2[j]>nums2[id]){

                    // Step 4: Store the next greater element in the answer vector or keep -1 if not found
                    ans[i]=nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};
