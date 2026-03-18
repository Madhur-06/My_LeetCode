/*
Problem: 141. Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/
Difficulty: Easy


Approach:
1. Use two pointers: slow and fast, both starting at head.
2. Move slow by one step and fast by two steps.
3. If fast reaches the end, there is no cycle.
4. If slow and fast meet at any point, a cycle exists.


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
    bool hasCycle(ListNode *head) {

        // Step 1: Check for empty list
        if(head == nullptr){
            return false;
        }

        // Step 2: Initialize slow and fast pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 3 & 4: Traverse and detect cycle
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            
            if(fast->next != nullptr){
                fast = fast->next;
            }
            else{
                return false;
            }

            if(fast == slow){
                return true;
            }
        }

        return false;        
    }
};
