/*
Problem: 876. Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/
Difficulty: Easy


Approach:
1. Use two pointers: slow and fast, both starting at head.
2. Move slow by one step and fast by two steps.
3. Continue until fast reaches the end of the list.
4. Slow pointer will be at the middle node.


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
    ListNode* middleNode(ListNode* head) {

        // Step 1: Initialize slow and fast pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 2 & 3: Move fast by 2 steps and slow by 1 step
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;

            if(fast->next != nullptr){
                fast = fast->next;
            }
        }

        // Step 4: Slow pointer is at the middle
        return slow;        
    }
};
