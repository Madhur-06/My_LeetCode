/*
Problem: 83. Remove Duplicates from Sorted List
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Difficulty: Easy


Approach:
1. Check if the linked list is empty and return nullptr if it is.
2. Traverse the sorted linked list using a pointer.
3. Remove consecutive duplicate nodes by updating next pointers.
4. Continue until the end of the list and return the modified head.


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
    ListNode* deleteDuplicates(ListNode* head) {

        // Step 1: Check if the linked list is empty and return nullptr if it is
        if(head==nullptr){
            return nullptr;
        }

        // Step 2: Traverse the sorted linked list using a pointer
        ListNode* temp=head;
        ListNode* nx;

        while(temp->next!=nullptr){

            // Step 3: Remove consecutive duplicate nodes by updating next pointers
            if(temp->val==temp->next->val){

                nx=temp->next->next;
                delete temp->next;
                temp->next=nx;
            }
            else{

                // Step 4: Continue until the end of the list and return the modified head
                temp=temp->next;
            }
        }

        return head;
    }
};
