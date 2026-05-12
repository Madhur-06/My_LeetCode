/*
Problem: 102. Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Difficulty: Medium


Approach:
1. Check if the root node is null and return an empty vector.
2. Use a queue to perform breadth-first traversal of the tree.
3. Process all nodes at the current level and store their values.
4. Push the left and right child nodes into the queue for the next level traversal.


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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Step 1: Check if the root node is null and return an empty vector
        if(root==nullptr){
            return {};
        }

        vector<vector<int>> ans;

        // Step 2: Use a queue to perform breadth-first traversal of the tree
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> sub_ans;

            // Step 3: Process all nodes at the current level and store their values
            for(int i=0;i<n;i++){

                // Step 4: Push the left and right child nodes into the queue for the next level traversal
                if((q.front())->left!=nullptr){
                    q.push((q.front())->left);
                }

                if((q.front())->right!=nullptr){
                    q.push((q.front())->right);
                }

                sub_ans.push_back((q.front())->val);
                q.pop();
            }

            ans.push_back(sub_ans);
        }

        return ans;
    }
};
