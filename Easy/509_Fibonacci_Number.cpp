/*
Problem: 509. Fibonacci Number
Link: https://leetcode.com/problems/fibonacci-number/
Difficulty: Easy


Approach:
1. Handle base cases where n is 0 or 1.
2. Use recursion to compute fib(n-1).
3. Use recursion to compute fib(n-2).
4. Return the sum of previous two Fibonacci numbers.


Time Complexity: O(2^n)
Space Complexity: O(n) (recursion stack)
*/

class Solution {
public:
    int fib(int n) {

        // Step 1: Base cases
        if(n==1||n==0){
            return n;
        }

        // Step 2, 3 & 4: Recursive Fibonacci calculation
        return fib(n-1)+fib(n-2);
    }
};
