/*
Problem: 503. Next Greater Element II
Link: https://leetcode.com/problems/next-greater-element-ii/
Difficulty: Medium


Approach:
1. Initialize result array with -1 for all elements.
2. Traverse each element and search circularly for its next greater element.
3. Use modulo operation to wrap around the array while checking elements.
4. Update result when a greater element is found and return final array.


Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output array)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Handle empty array
        if (n == 0) return {};

        vector<int> res(n, -1);

        // Step 2 & 3: Search circularly for next greater element
        for (int i = 0; i < n; ++i) {
            for (int step = 1; step < n; ++step) {
                int idx = (i + step) % n;

                if (nums[idx] > nums[i]) {
                    // Step 4: Update result
                    res[i] = nums[idx];
                    break;
                }
            }
        }

        return res;
    }
};
