/*
Problem: 234. Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/
Difficulty: Easy


Approach:
1. Use slow and fast pointers to find the middle of the list.
2. Reverse the second half of the linked list.
3. Compare the first half and reversed second half node by node.
4. If all values match, the list is a palindrome.


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

    // Helper function to reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Step 1: Handle edge cases
        if(!head || !head->next)
            return true;

        // Step 2: Find middle using slow & fast
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 

        // Step 3: Reverse second half
        slow = reverse(slow);

        // Step 4: Compare both halves
        ListNode* first = head;
        ListNode* second = slow;

        while(second){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
