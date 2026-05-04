/*
Problem: 155. Min Stack
Link: https://leetcode.com/problems/min-stack/
Difficulty: Medium


Approach:
1. Use two stacks: one for storing elements and one for tracking minimums.
2. Push element to main stack and update min stack if needed.
3. While popping, remove element from min stack if it matches current minimum.
4. Return top element or minimum using respective stack tops.


Time Complexity: O(1) for all operations
Space Complexity: O(n)
*/

class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    // Step 2: Push element and update min stack
    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    // Step 3: Pop element and update min stack if needed
    void pop() {
        int x = st.top();
        st.pop();

        if (x == minSt.top()) {
            minSt.pop();
        }
    }

    // Step 4: Return top element
    int top() {
        return st.top();
    }

    // Step 4: Return minimum element
    int getMin() {
        return minSt.top();
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
