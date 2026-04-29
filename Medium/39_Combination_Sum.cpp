/*
Problem: 39. Combination Sum
Link: https://leetcode.com/problems/combination-sum/
Difficulty: Medium


Approach:
1. Use recursion (backtracking) to explore all possible combinations.
2. At each index, choose the element if it does not exceed target.
3. Reduce target and continue with same index to allow reuse of elements.
4. Skip current element and move to next index to explore other combinations.


Time Complexity: O(2^n * k) (k = average combination length)
Space Complexity: O(k) (recursion stack)
*/

class Solution {
public:
    void findcombinations(int idx, vector<int> &arr, int target,
                          vector<vector<int>> &ans, vector<int> &ds) {

        // Step 1: Base case
        if (idx == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Step 2 & 3: Pick current element if valid
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findcombinations(idx, arr, target - arr[idx], ans, ds);
            ds.pop_back();
        }

        // Step 4: Skip current element
        findcombinations(idx + 1, arr, target, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        // Step 1, 2, 3 & 4: Start recursion
        findcombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
