/*
Problem: 206. Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/
Difficulty: Easy


Approach:
1. Initialize three pointers: prev (null), curr (head), and next.
2. Traverse the list and reverse the link by pointing current node to prev.
3. Move prev and curr one step forward each iteration.
4. At the end, prev will be the new head of the reversed list.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Step 1: Initialize pointers
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Step 2 & 3: Reverse links and move pointers
        while (curr != nullptr) {
            ListNode* next = curr->next; 
            curr->next = prev;           
            prev = curr;                 
            curr = next;                 
        }

        // Step 4: Return new head
        return prev;
    }
};
