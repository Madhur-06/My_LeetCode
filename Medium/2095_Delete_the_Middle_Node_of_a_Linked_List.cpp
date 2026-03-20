/*
Problem: 2095. Delete the Middle Node of a Linked List
Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
Difficulty: Medium


Approach:
1. Use slow and fast pointers to find the middle node.
2. Keep track of the previous node of slow.
3. When fast reaches the end, slow will be at the middle.
4. Remove the middle node by updating the previous node’s next pointer.


Time Complexity: O(n)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Step 1: Handle single node case
        if(head->next == nullptr){
            return nullptr;
        }

        // Step 2: Initialize pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Step 3: Find middle node
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 4: Delete middle node
        prev->next = slow->next;
        
        return head;
    }
};
