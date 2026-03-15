/*
Problem: 7. Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/
Difficulty: Medium


Approach:
1. Extract digits from the number using modulo (x % 10).
2. Build the reversed number by multiplying the current result by 10 and adding the digit.
3. Continue until all digits are processed.
4. If the reversed number exceeds 32-bit integer range, return 0.


Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

class Solution {                      
public:
    int reverse(int x) {

        long ans = 0;      

        // Step 1, 2 & 3: Extract digits and build reversed number
        while(x != 0){
            ans = ans * 10 + x % 10; 
            x = x / 10;     
        }

        // Step 4: Check for 32-bit integer overflow
        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }

        return int(ans);  
    }
};
