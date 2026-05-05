/*
Problem: 496. Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
Difficulty: Easy


Approach:
1. Traverse nums2 from right to left using a monotonic stack.
2. For each element, remove smaller elements and find next greater.
3. Store next greater elements in a hashmap for quick lookup.
4. Build result for nums1 using the precomputed hashmap.


Time Complexity: O(n + m)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> s;

        // Step 1 & 2: Build next greater mapping using stack
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            next[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> res;

        // Step 3 & 4: Build result using hashmap
        for (int num : nums1) {
            res.push_back(next[num]);
        }
        return res;
    }
};
