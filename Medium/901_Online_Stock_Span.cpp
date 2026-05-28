/*
Problem: 901. Online Stock Span
Link: https://leetcode.com/problems/online-stock-span/
Difficulty: Medium


Approach:
1. Use a monotonic stack to store stock prices along with their indices.
2. Remove smaller or equal prices to find the nearest greater previous price.
3. Calculate the span using the index difference or full range if no greater price exists.
4. Push the current price with its index into the stack and return the span.


Time Complexity: O(1) amortized per query
Space Complexity: O(n)
*/

class StockSpanner {
public:

    // Step 1: Use a monotonic stack to store stock prices along with their indices
    stack<pair<int,int>> st; 
    int sz=0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span;

        // Step 2: Remove smaller or equal prices to find the nearest greater previous price
        while (!st.empty()&&st.top().first<=price){
            st.pop();
        }

        // Step 3: Calculate the span using the index difference or full range if no greater price exists
        if(st.empty()){
            st.push({price,sz});
            span=sz+1;
            sz++;
            return span;
        }

        span=sz-st.top().second;

        // Step 4: Push the current price with its index into the stack and return the span
        st.push({price,sz});
        sz++;
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
