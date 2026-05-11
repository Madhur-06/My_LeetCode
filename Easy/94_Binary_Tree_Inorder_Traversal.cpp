/*
Problem: 94. Binary Tree Inorder Traversal
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
Difficulty: Easy


Approach:
1. Create a recursive helper function for inorder traversal.
2. Check if the current node is null and return if true.
3. Recursively traverse the left subtree and store the current node value.
4. Recursively traverse the right subtree to complete inorder traversal.


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

        // Step 3: Recursively traverse the left subtree and store the current node value
        helper(root->left,ans);
        ans.push_back(root->val);

        // Step 4: Recursively traverse the right subtree to complete inorder traversal
        helper(root->right,ans);

        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {

        // Step 1: Create a recursive helper function for inorder traversal
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};
