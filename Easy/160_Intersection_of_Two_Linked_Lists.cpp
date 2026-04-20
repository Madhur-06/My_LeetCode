/*
Problem: 160. Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Difficulty: Easy


Approach:
1. Calculate lengths of both linked lists.
2. Align both lists by moving the pointer of longer list by the length difference.
3. Traverse both lists together to find the intersection node.
4. Return the intersection node if found, otherwise return nullptr.


Time Complexity: O(n + m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int c1 = 0;

        // Step 1: Calculate length of list A
        while(temp1 != nullptr){
            c1++;
            temp1 = temp1->next;
        }

        int c2 = 0;

        // Step 1: Calculate length of list B
        while(temp2 != nullptr){
            c2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        // Step 2: Align both lists
        if(c1 > c2){
            int diff = c1 - c2;
            while(diff--){
                temp1 = temp1->next;
            }
        } else {
            int diff = c2 - c1;
            while(diff--){
                temp2 = temp2->next;
            }
        }

        // Step 3: Traverse and find intersection
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Step 4: No intersection
        return nullptr;
    }
};
