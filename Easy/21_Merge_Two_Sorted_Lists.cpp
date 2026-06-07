/*
Problem: 21. Merge Two Sorted Lists
Link: https://leetcode.com/problems/merge-two-sorted-lists/
Difficulty: Easy


Approach:
1. Create a dummy node to simplify the merging process.
2. Traverse both sorted linked lists simultaneously.
3. Attach the smaller node to the merged list and move the corresponding pointer.
4. Append the remaining nodes from the non-empty list and return the merged list.


Time Complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Step 1: Create a dummy node to simplify the merging process
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* dummyNode = new ListNode;
        ListNode* temp = dummyNode;

        // Step 2: Traverse both sorted linked lists simultaneously
        while(curr1 && curr2) {

            // Step 3: Attach the smaller node to the merged list and move the corresponding pointer
            if(curr1->val < curr2->val) {
                temp->next = curr1;
                temp = curr1;
                curr1 = curr1->next;
            }
            else {
                temp->next = curr2;
                temp = curr2;
                curr2 = curr2->next;
            }
        }

        // Step 4: Append the remaining nodes from the non-empty list and return the merged list
        if(curr1) temp->next = curr1;
        if(curr2) temp->next = curr2;

        return dummyNode->next;
    }
};
