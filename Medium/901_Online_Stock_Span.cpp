/*
Problem: 901. Online Stock Span
Link: https://leetcode.com/problems/online-stock-span/
Difficulty: Medium


Approach:
1. Use a monotonic stack to store stock prices with their span contribution.
2. Push the first stock price with span information into the stack.
3. Remove smaller or equal prices while accumulating their span contribution.
4. Push the current price with accumulated span data and return the total span.


Time Complexity: O(1) amortized per query
Space Complexity: O(n)
*/

class StockSpanner {
public:

    // Step 1: Use a monotonic stack to store stock prices with their span contribution
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {

        // Step 2: Push the first stock price with span information into the stack
        if(st.empty()){
            st.push({price,0});
            return 1;
        }

        int span=1,p_c=0;

        // Step 3: Remove smaller or equal prices while accumulating their span contribution
        while((!st.empty())&&(price>=st.top().first)){
            span=span+st.top().second+1;
            p_c=p_c+st.top().second+1;
            st.pop();
        }

        // Step 4: Push the current price with accumulated span data and return the total span
        st.push({price,p_c});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
