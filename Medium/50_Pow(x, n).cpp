/*
Problem: 50. Pow(x, n)
Link: https://leetcode.com/problems/powx-n/
Difficulty: Medium


Approach:
1. Convert the exponent to a positive long long value to handle negative powers safely.
2. Use binary exponentiation to repeatedly process the exponent bits.
3. Multiply the answer when the current exponent bit is set and square the base otherwise.
4. Return the reciprocal of the answer for negative exponents or the answer itself for positive exponents.


Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {

        // Step 1: Convert the exponent to a positive long long value to handle negative powers safely
        double ans = 1.0;
        long long nn = n;

        if(nn < 0)
            nn = -1 * nn;

        // Step 2: Use binary exponentiation to repeatedly process the exponent bits
        while(nn > 0) {

            // Step 3: Multiply the answer when the current exponent bit is set and square the base otherwise
            if(nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            }
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // Step 4: Return the reciprocal of the answer for negative exponents or the answer itself for positive exponents
        if(n < 0)
            return 1 / (double) ans;

        return ans;
    }
};
