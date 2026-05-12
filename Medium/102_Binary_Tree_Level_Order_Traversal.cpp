/*
Problem: 102. Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Difficulty: Medium


Approach:
1. Check if the root node is null and return an empty answer vector.
2. Use a queue to perform breadth-first traversal level by level.
3. Process all nodes of the current level and store their values.
4. Push the left and right children of each node into the queue for the next level.


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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // Step 1: Check if the root node is null and return an empty answer vector
        if (!root)
            return ans;

        // Step 2: Use a queue to perform breadth-first traversal level by level
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            // Step 3: Process all nodes of the current level and store their values
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                // Step 4: Push the left and right children of each node into the queue for the next level
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
