/*
Problem: 23. Merge k Sorted Lists
Link: https://leetcode.com/problems/merge-k-sorted-lists/
Difficulty: Hard


Approach:
1. Repeatedly merge linked lists in pairs until only one list remains.
2. Traverse two sorted lists simultaneously and compare node values.
3. Attach the smaller node to the merged list and move the pointer forward.
4. Append remaining nodes and return the final merged linked list.


Time Complexity: O(n log k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Step 1: Repeatedly merge linked lists in pairs until only one list remains
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {

            vector<ListNode*> temp;

            for (size_t i = 0; i < lists.size(); i += 2) {

                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;

                temp.push_back(mergeLists(l1, l2));
            }

            lists = move(temp);
        }

        return lists[0];        
    }

private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {

        ListNode dummy;
        ListNode* node = &dummy;

        // Step 2: Traverse two sorted lists simultaneously and compare node values
        while (l1 && l2) {

            // Step 3: Attach the smaller node to the merged list and move the pointer forward
            if (l1->val > l2->val) {
                node->next = l2;
                l2 = l2->next;
            } 
            else {
                node->next = l1;
                l1 = l1->next;
            }

            node = node->next;
        }

        // Step 4: Append remaining nodes and return the final merged linked list
        node->next = l1 ? l1 : l2;

        return dummy.next;
    }    
};
