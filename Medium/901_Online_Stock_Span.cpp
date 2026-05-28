/*
Problem: 901. Online Stock Span
Link: https://leetcode.com/problems/online-stock-span/
Difficulty: Medium


Approach:
1. Store incoming stock prices in a vector for future span calculation.
2. Add the current price to the vector whenever next() is called.
3. Traverse backward to count consecutive prices less than or equal to the current price.
4. Stop when a greater price is found and return the calculated span.


Time Complexity: O(n) per query
Space Complexity: O(n)
*/

class StockSpanner {
public:

    // Step 1: Store incoming stock prices in a vector for future span calculation
    vector<int> pr;

    StockSpanner() {
        
    }
    
    int next(int price) {

        // Step 2: Add the current price to the vector whenever next() is called
        pr.push_back(price);

        int n=pr.size();
        int span=0;

        // Step 3: Traverse backward to count consecutive prices less than or equal to the current price
        for(int i=n-1;i>=0;i--){

            // Step 4: Stop when a greater price is found and return the calculated span
            if(pr[i]>price){
                break;
            }

            span++;
        }
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
