/*
Problem: 9. Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
Difficulty: Easy


Approach:
1. If the number is negative, it cannot be a palindrome.
2. Reverse the digits of the number using modulo and division.
3. Compare the reversed number with the original number.
4. If both are equal, the number is a palindrome.


Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        // Step 1: Negative numbers cannot be palindrome
        if(x < 0){
            return false;
        }

        long rx = 0;
        int sx = x;

        // Step 2: Reverse the number
        while(sx != 0){
            rx = rx * 10 + sx % 10;
            sx = sx / 10;
        }

        // Step 3 & 4: Compare reversed number with original
        if(rx == x){
            return true;
        }

        return false;
    }
};
