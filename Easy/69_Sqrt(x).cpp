/*
Problem: 69. Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/
Difficulty: Easy


Approach:
1. Use binary search on the range [1, x] to find the square root.
2. Calculate the middle value and compare it with x using division to avoid overflow.
3. Narrow the search space based on whether the square is too large or too small.
4. Return the exact square root if found, otherwise return the floor value.


Time Complexity: O(log x)
Space Complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return x;

        // Step 1: Use binary search on the range [1, x] to find the square root
        int first = 1, last = x;

        while (first <= last) {

            // Step 2: Calculate the middle value and compare it with x using division to avoid overflow
            int mid = first + (last - first) / 2;

            if (mid == x / mid)

                // Step 4: Return the exact square root if found, otherwise return the floor value
                return mid;

            // Step 3: Narrow the search space based on whether the square is too large or too small
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }

        // Step 4: Return the exact square root if found, otherwise return the floor value
        return last;
    }
};
