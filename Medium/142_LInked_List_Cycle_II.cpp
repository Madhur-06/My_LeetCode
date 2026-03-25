/*
Problem: 142. Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/
Difficulty: Medium


Approach:
1. Use slow and fast pointers to detect a cycle in the list.
2. If they meet, a cycle exists.
3. Move one pointer to head while keeping the other at meeting point.
4. Move both one step at a time; their meeting point is the start of the cycle.


Time Complexity: O(n)
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
    ListNode *detectCycle(ListNode *head) {

        // Step 1: Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Detect cycle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){

                // Step 3: Move slow to head
                slow = head;

                // Step 4: Find start of cycle
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};
