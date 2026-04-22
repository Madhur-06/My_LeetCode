/*
Problem: 25. Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Difficulty: Hard


Approach:
1. Check if there are at least k nodes available for reversal.
2. Reverse the first k nodes using helper function.
3. Recursively process remaining list in groups of k.
4. Connect reversed part with recursive result and return new head.


Time Complexity: O(n)
Space Complexity: O(n) (recursion stack)
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

ListNode* reverse_list(ListNode* head,int k){

    ListNode* prev=nullptr;
    ListNode* curr=head;

    // Step 2: Reverse first k nodes
    while(curr!=nullptr&&k>0){
        ListNode* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        k--;
    }
    return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;

        // Step 1: Check if k nodes exist
        for (int i=0;i<k;i++){
            if (temp==nullptr){
                return head; 
            }
            temp=temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* newHead=reverse_list(head, k);

        // Step 3 & 4: Recurse for remaining and connect
        head->next=reverseKGroup(temp,k);
        
        return newHead;
    }
};
