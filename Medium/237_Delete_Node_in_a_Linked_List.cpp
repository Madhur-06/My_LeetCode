/*
Problem: 237. Delete Node in a Linked List
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
Difficulty: Medium


Approach:
1. Since the node to delete is given (not the head), copy the value of the next node into the current node.
2. Store the next node in a temporary pointer.
3. Update the current node’s next pointer to skip the next node.
4. Delete the temporary node to remove it from memory.


Time Complexity: O(1)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {

        // Step 1 & 2: Copy value of next node and store it
        ListNode* temp = node->next;
        node->val = temp->val;

        // Step 3: Skip the next node
        node->next = temp->next;

        // Step 4: Delete the node
        delete temp;
    }
};
