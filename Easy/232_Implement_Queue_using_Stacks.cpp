/*
Problem: 232. Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/
Difficulty: Easy


Approach:
1. Use two stacks to simulate queue operations.
2. Move all elements from the main stack to the helper stack before inserting a new element.
3. Push the new element into the main stack and restore previous elements back.
4. Perform pop, peek, and empty operations directly using the main stack.


Time Complexity: Push -> O(n), Pop -> O(1), Peek -> O(1), Empty -> O(1)
Space Complexity: O(n)
*/

class MyQueue {
public:

    int sz=0;
    stack<int> s1;
    stack<int> s2;

    MyQueue() {

    }
    
    void push(int x) {

        // Step 2: Move all elements from the main stack to the helper stack before inserting a new element
        for(int i=0;i<sz;i++){
            s2.push(s1.top());
            s1.pop();
        }

        // Step 3: Push the new element into the main stack and restore previous elements back
        s1.push(x);

        for(int i=0;i<sz;i++){
            s1.push(s2.top());
            s2.pop();
        }

        sz++;
    }
    
    int pop() {

        // Step 4: Perform pop, peek, and empty operations directly using the main stack
        int x=s1.top();
        s1.pop();
        sz--;

        return x;
    }
    
    int peek() {

        // Step 4: Perform pop, peek, and empty operations directly using the main stack
        return s1.top();
        
    }
    
    bool empty() {

        // Step 4: Perform pop, peek, and empty operations directly using the main stack
        if(sz==0){
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
