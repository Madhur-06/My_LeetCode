/*
Problem: 700. Search in a Binary Search Tree
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
Difficulty: Easy


Approach:
1. Check if the current node is null and return nullptr if reached.
2. Compare the target value with the current node value.
3. Recursively search the right subtree if the target is greater or the left subtree if smaller.
4. Return the current node when the target value is found.


Time Complexity: O(h)
Space Complexity: O(h)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // Step 1: Check if the current node is null and return nullptr if reached
        if (!root)
            return nullptr;

        // Step 2: Compare the target value with the current node value
        if (root->val < val) {

            // Step 3: Recursively search the right subtree if the target is greater or the left subtree if smaller
            return searchBST(root->right, val);
        } 
        else if (root->val > val) {

            // Step 3: Recursively search the right subtree if the target is greater or the left subtree if smaller
            return searchBST(root->left, val);
        } 
        else {

            // Step 4: Return the current node when the target value is found
            return root;
        }
    }
};
