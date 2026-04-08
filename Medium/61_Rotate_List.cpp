/*
Problem: 61. Rotate List
Link: https://leetcode.com/problems/rotate-list/
Difficulty: Medium


Approach:
1. Calculate the size of the linked list.
2. Reduce k using modulo to avoid unnecessary full rotations.
3. Perform k rotations by moving the last node to the front each time.
4. Return the updated head of the rotated list.


Time Complexity: O(n * k)
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Step 1: Check for empty list
        if(!head) return head;
        
        int size = 0;
        ListNode *cal = head;

        // Step 1: Calculate size of list
        while(cal != NULL){
            size++;
            cal = cal->next;
        }

        // Step 2: Normalize k
        k = k % size;

        // Step 3: Rotate list k times
        for(int i = 0; i < k; i++){
            ListNode *temp = head;

            while(temp->next->next != NULL){
                temp = temp->next;
            }

            temp->next->next = head;
            head = temp->next;
            temp->next = NULL;
        }

        // Step 4: Return new head
        return head;
    }
};
