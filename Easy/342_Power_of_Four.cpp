/*
Problem: 342. Power of Four
Link: https://leetcode.com/problems/power-of-four/
Difficulty: Easy


Approach:
1. Handle edge case where n is less than or equal to 0.
2. Check if n is a power of two using (n & (n-1)) == 0.
3. Use mask 0x55555555 to ensure the set bit is at even position (power of four property).
4. Return true if both conditions satisfy, otherwise return false.


Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // Step 1: Check for non-positive numbers
        if(n <= 0) return false;

        // Step 2 & 3: Check power of two and valid bit position
        if( ((n & (n - 1)) == 0) && (n & 0x55555555) ) {
            return true;
        }

        // Step 4: Otherwise not a power of four
        return false;
    }
};
