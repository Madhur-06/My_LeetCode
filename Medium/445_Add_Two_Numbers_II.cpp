/*
Problem: 445. Add Two Numbers II
Link: https://leetcode.com/problems/add-two-numbers-ii/
Difficulty: Medium


Approach:
1. Reverse both linked lists to simplify addition from least significant digit.
2. Traverse both lists and add corresponding digits along with carry.
3. Create new nodes for each digit of the result and maintain carry.
4. Reverse the final result list to restore correct order.


Time Complexity: O(n + m)
Space Complexity: O(1) (excluding result list)
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

        ListNode* prev = NULL;
        ListNode* curr = head;
        
        // Step 1: Reverse linked list
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Step 1: Reverse both lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        // Step 2 & 3: Add digits and build result list
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        ListNode* l3 = dummy->next;

        // Step 4: Reverse result to restore order
        return reverseList(l3);
    }
};
