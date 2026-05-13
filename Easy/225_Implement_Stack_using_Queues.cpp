/*
Problem: 225. Implement Stack using Queues
Link: https://leetcode.com/problems/implement-stack-using-queues/
Difficulty: Easy


Approach:
1. Use a single queue to simulate stack operations.
2. Push the new element into the queue and rotate previous elements behind it.
3. Remove and return the front element of the queue for pop operation.
4. Return the front element for top operation and check size for empty operation.


Time Complexity: Push -> O(n), Pop -> O(1), Top -> O(1), Empty -> O(1)
Space Complexity: O(n)
*/

class MyStack {
public:
    int sz=0;
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {

        // Step 2: Push the new element into the queue and rotate previous elements behind it
        sz++;
        q.push(x);

        for(int i=0;i<sz-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {

        // Step 3: Remove and return the front element of the queue for pop operation
        int x=q.front();
        q.pop();
        sz--;
        
        return x;
    }
    
    int top() {

        // Step 4: Return the front element for top operation and check size for empty operation
        return q.front();
    }
    
    bool empty() {

        // Step 4: Return the front element for top operation and check size for empty operation
        if(sz==0){
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
