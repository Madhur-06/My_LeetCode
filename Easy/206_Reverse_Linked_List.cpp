/*
Problem: 206. Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/
Difficulty: Easy


Approach:
1. Initialize three pointers: prev, curr, and nxt for traversal.
2. Traverse the list while updating next pointer of each node.
3. Reverse the link by pointing current node to previous node.
4. Move pointers forward and return new head (prev).


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
    ListNode* reverseList(ListNode* head) {

        // Step 1:Initialize pointers
        ListNode *curr=head;
        ListNode *nxt=head;
        ListNode *prev=nullptr;

        // Step 2 & 3: Traverse and reverse links
        while(curr!=nullptr){
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        // Step 4: Return new head
        return prev;
    }
};
