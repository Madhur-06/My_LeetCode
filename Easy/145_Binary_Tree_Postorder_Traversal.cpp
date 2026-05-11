/*
Problem: 145. Binary Tree Postorder Traversal
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
Difficulty: Easy


Approach:
1. Create a recursive helper function for postorder traversal.
2. Check if the current node is null and return if true.
3. Recursively traverse the left subtree followed by the right subtree.
4. Store the current node value after traversing both subtrees.


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

        // Step 3: Recursively traverse the left subtree followed by the right subtree
        helper(root->left,ans);
        helper(root->right,ans);

        // Step 4: Store the current node value after traversing both subtrees
        ans.push_back(root->val);

        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {

        // Step 1: Create a recursive helper function for postorder traversal
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};
