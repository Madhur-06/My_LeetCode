/*
Problem: 328. Odd Even Linked List
Link: https://leetcode.com/problems/odd-even-linked-list/
Difficulty: Medium


Approach:
1. Separate nodes into two lists: odd-indexed and even-indexed.
2. Traverse the list and rearrange pointers to group odds and evens.
3. Maintain a reference to the head of the even list.
4. At the end, connect the odd list with the even list.


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
    ListNode* oddEvenList(ListNode* head) {

        // Step 1: Handle edge cases
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 2: Initialize odd and even pointers
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Step 3: Rearrange nodes
        while (even != nullptr && even->next != nullptr) {

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        // Step 4: Connect odd list with even list
        odd->next = evenHead;

        return head;
    }
};
