/*
Problem: 50. Pow(x, n)
Link: https://leetcode.com/problems/powx-n/
Difficulty: Medium


Approach:
1. Use binary exponentiation to compute power efficiently.
2. Handle negative exponent by converting it to reciprocal of positive exponent.
3. If exponent is odd, multiply x and reduce the problem size.
4. If exponent is even, square x and divide exponent by 2.


Time Complexity: O(log n)
Space Complexity: O(log n) (recursion stack)
*/

double binaryExp(double x, long n) {

    // Step 1: Base case
    if (n == 0) {
        return 1;
    }
    
    // Step 2: Handle negative exponent
    if (n < 0) {
        return 1.0 / binaryExp(x, -n);
    }
    
    // Step 3: If n is odd
    if (n % 2 == 1) {
        return x * binaryExp(x * x, (n - 1) / 2);
    } 
    else {
        // Step 4: If n is even
        return binaryExp(x * x, n / 2);
    }
}  

class Solution {
public:
    double myPow(double x, int n) {
        return binaryExp(x, static_cast<long>(n));
    }
};
