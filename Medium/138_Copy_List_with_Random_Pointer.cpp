/*
Problem: 138. Copy List with Random Pointer
Link: https://leetcode.com/problems/copy-list-with-random-pointer/
Difficulty: Medium


Approach:
1. Traverse the linked list and create a copy node for every original node.
2. Store the mapping between original nodes and copied nodes using a hash map.
3. Traverse the list again to assign next and random pointers for copied nodes.
4. Return the copied head node from the hash map.


Time Complexity: O(n)
Space Complexity: O(n)
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

        // Step 2: Store the mapping between original nodes and copied nodes using a hash map
        std::unordered_map<Node*, Node*> hashMap;

        // Step 1: Traverse the linked list and create a copy node for every original node
        Node* cur = head;

        while (cur) {
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        // Step 3: Traverse the list again to assign next and random pointers for copied nodes
        while (cur) {

            Node* copy = hashMap[cur];

            copy->next = hashMap[cur->next];
            copy->random = hashMap[cur->random];

            cur = cur->next;
        }

        // Step 4: Return the copied head node from the hash map
        return hashMap[head];        
    }
};
