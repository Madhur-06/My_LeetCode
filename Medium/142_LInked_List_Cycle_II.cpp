/*
Problem: 142. Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/
Difficulty: Medium


Approach:
1. Use slow and fast pointers to detect if a cycle exists.
2. If no cycle is found, return nullptr.
3. If a cycle exists, traverse the list and store visited nodes in a set.
4. The first node that repeats in the set is the start of the cycle.


Time Complexity: O(n)
Space Complexity: O(n)
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
    ListNode *detectCycle(ListNode *head) {
        
        // Step 1: Handle empty list
        if(head == nullptr){
            return nullptr;
        }

        // Step 2: Detect cycle using slow and fast pointers
        ListNode* fast = head;
        ListNode* slow = head;
        int flag = 0;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast){
                flag = 1;
                break;
            }
        }

        // Step 3: If no cycle, return nullptr
        if(flag == 0){
            return nullptr;
        }

        // Step 4: Use set to find starting node of cycle
        unordered_set<ListNode*> s;
        ListNode* temp = head;

        while(s.find(temp) == s.end()){
            s.insert(temp);
            temp = temp->next;
        }
        return temp;
    }
};
