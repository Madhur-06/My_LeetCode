/*
Problem: 901. Online Stock Span
Link: https://leetcode.com/problems/online-stock-span/
Difficulty: Medium


Approach:
1. Use a monotonic stack to store stock prices along with their span values.
2. Initialize the span of the current stock price as 1.
3. Remove smaller or equal prices while adding their span contribution.
4. Push the current price with its calculated span and return the span.


Time Complexity: O(1) amortized per query
Space Complexity: O(n)
*/

class StockSpanner {
public:

    // Step 1: Use a monotonic stack to store stock prices along with their span values
    stack<pair<int,int>> st; 

    StockSpanner() {
        
    }
    
    int next(int price) {

        // Step 2: Initialize the span of the current stock price as 1
        int span = 1;

        // Step 3: Remove smaller or equal prices while adding their span contribution
        while (!st.empty()&&st.top().first<=price) {
            span=span+st.top().second;
            st.pop();
        }

        // Step 4: Push the current price with its calculated span and return the span
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
