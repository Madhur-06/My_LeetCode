/*
Problem: 155. Min Stack
Link: https://leetcode.com/problems/min-stack/
Difficulty: Medium


Approach:
1. Use a stack of pairs to store both value and current minimum.
2. Push the value along with the minimum value till that point into the stack.
3. Remove the top element directly from the stack during pop operation.
4. Return the top value or minimum value using the top pair element.


Time Complexity: Push -> O(1), Pop -> O(1), Top -> O(1), GetMin -> O(1)
Space Complexity: O(n)
*/

class MinStack {
public:

    // Step 1: Use a stack of pairs to store both value and current minimum
    stack<pair<int,int>> s;

    MinStack() {

    }
    
    void push(int val) {
        
        // Step 2: Push the value along with the minimum value till that point into the stack
        if(s.empty()){
            s.push({val,val});
        }
        else{
            s.push({val,min(val,s.top().second)});
        }
    }
    
    void pop() {

        // Step 3: Remove the top element directly from the stack during pop operation
        s.pop();
    }
    
    int top() {

        // Step 4: Return the top value or minimum value using the top pair element
        return s.top().first;
    }
    
    int getMin() {

        // Step 4: Return the top value or minimum value using the top pair element
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
