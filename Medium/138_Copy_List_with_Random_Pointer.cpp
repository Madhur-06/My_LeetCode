/*
Problem: 138. Copy List with Random Pointer
Link: https://leetcode.com/problems/copy-list-with-random-pointer/
Difficulty: Medium


Approach:
1. Create a copy of each node and insert it next to the original node in the list.
2. Assign random pointers for copied nodes using original node connections.
3. Separate the interleaved list into original and copied lists.
4. Return the head of the deep copied list.


Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Step 1: Create copy nodes and insert them next to originals
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        
        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate original and copied list
        Node* old_head = head;
        Node* new_head = head->next;
        Node* curr_old = old_head;
        Node* curr_new = new_head;
        
        while (curr_old) {
            curr_old->next = curr_old->next->next;
            curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        
        // Step 4: Return copied list head
        return new_head;       
    }
};
