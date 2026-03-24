/*
Problem: 234. Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/
Difficulty: Easy


Approach:
1. Traverse the linked list and store values in a vector.
2. Use two pointers (left and right) to compare elements from both ends.
3. Move pointers inward while values are equal.
4. If all corresponding elements match, the list is a palindrome.


Time Complexity: O(n)
Space Complexity: O(n)
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
    bool isPalindrome(ListNode* head) {

        // Step 1: Store list values in vector
        vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }
        
        // Step 2 & 3: Compare from both ends
        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right]) {
            left++;
            right--;
        }

        // Step 4: Check if palindrome
        return left >= right;
    }
};
