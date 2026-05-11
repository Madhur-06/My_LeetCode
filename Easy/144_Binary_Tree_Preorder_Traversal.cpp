/*
Problem: 144. Binary Tree Preorder Traversal
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
Difficulty: Easy


Approach:
1. Create a recursive helper function for preorder traversal.
2. Check if the current node is null and return if true.
3. Store the current node value in the answer vector.
4. Recursively traverse the left subtree followed by the right subtree.


Time Complexity: O(n)
Space Complexity: O(n)
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
    void helper(TreeNode* root,vector<int> &ans){
        
        // Step 2: Check if the current node is null and return if true
        if(root==nullptr){
            return;
        }

        // Step 3: Store the current node value in the answer vector
        ans.push_back(root->val);

        // Step 4: Recursively traverse the left subtree followed by the right subtree
        helper(root->left,ans);
        helper(root->right,ans);

        return;
    }
        
    vector<int> preorderTraversal(TreeNode* root) {

        // Step 1: Create a recursive helper function for preorder traversal
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};
