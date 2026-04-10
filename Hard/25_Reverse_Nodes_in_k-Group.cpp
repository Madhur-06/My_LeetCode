/*
Problem: 25. Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Difficulty: Hard


Approach:
1. Check if there are at least k nodes available to reverse.
2. Reverse the first k nodes using a helper function.
3. Recursively process the remaining list in groups of k.
4. Connect reversed part with the result of next recursion and return new head.


Time Complexity: O(n)
Space Complexity: O(n) (due to recursion)
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

ListNode* reverse(ListNode* head,int k){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* Next=NULL;

    // Step 2: Reverse first k nodes
    while(curr && k--){
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        int count=0;

        // Step 1: Check if k nodes exist
        while(temp && count<k){
            count++;
            temp=temp->next;
        }

        if(count<k) return head;

        // Step 2: Reverse first k nodes
        ListNode* newHead=reverse(head,k);

        // Step 3 & 4: Recursively process remaining and connect
        head->next=reverseKGroup(temp,k);

        return newHead;
    }
};
