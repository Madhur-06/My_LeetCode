/*
Problem: 160. Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Difficulty: Easy


Approach:
1. Traverse list A and for each node, traverse list B.
2. Compare nodes from both lists to check if they are the same.
3. If a common node is found, return it as the intersection point.
4. If no intersection exists, return nullptr.


Time Complexity: O(n * m)
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

        // Step 1: Initialize pointers
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Step 2 & 3: Compare nodes of both lists
        while(tempA != nullptr){
            while(tempB != nullptr){
                if(tempA == tempB){
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
            tempB = headB;
        }

        // Step 4: No intersection found
        return nullptr;
    }
};
