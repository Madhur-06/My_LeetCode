/*
Problem: 19. Remove Nth Node From End of List
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Difficulty: Medium


Approach:
1. Use two pointers (fast and slow) and move fast n steps ahead.
2. If fast becomes null, remove the head node.
3. Move both pointers until fast reaches the last node.
4. Delete the target node and adjust links.


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast=head;
        ListNode* slow=head;

        // Step 1: Move fast pointer n steps ahead
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }

        // Step 2: If removing head node
        if(fast==nullptr){
            ListNode* dl=head;
            head=head->next;
            delete dl;
            return head;
        }

        // Step 3: Move both pointers together
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        // Step 4: Delete target node
        ListNode* dl=slow->next;
        slow->next=dl->next;

        delete dl;

        return head;
    }
};
