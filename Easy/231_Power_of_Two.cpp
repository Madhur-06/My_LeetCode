/*
Problem: 231. Power of Two
Link: https://leetcode.com/problems/power-of-two/
Difficulty: Easy


Approach:
1. Handle edge case where n is less than or equal to 0.
2. Use bit manipulation property: power of two has only one set bit.
3. Check if (n & (n-1)) equals 0 to confirm only one set bit exists.
4. Return true if condition satisfies, otherwise return false.


Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        // Step 1: Check for non-positive numbers
        if(n<=0){
            return false;
        }

        // Step 2 & 3: Check if only one set bit using (n & (n-1))
        if((n&(n-1))==0){
            return true;
        }
        
        // Step 4: Otherwise not a power of two
        return false;
    }
};
