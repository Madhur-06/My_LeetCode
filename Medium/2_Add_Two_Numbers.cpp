/*
Problem: 2. Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/
Difficulty: Medium


Approach:
1. Traverse both linked lists simultaneously while maintaining a carry.
2. At each step, sum corresponding digits and the carry.
3. Create a new node with the digit (sum % 10) and update carry (sum / 10).
4. Continue until both lists and carry are exhausted, then return the result list.


Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Step 1: Initialize dummy node and carry
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        // Step 2 & 3: Traverse lists and compute sum
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // Step 4: Return result list
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
