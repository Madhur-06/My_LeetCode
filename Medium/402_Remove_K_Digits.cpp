/*
Problem: 402. Remove K Digits
Link: https://leetcode.com/problems/remove-k-digits/
Difficulty: Medium


Approach:
1. Traverse the number string and maintain a monotonic increasing sequence using index manipulation.
2. Remove larger previous digits while k is greater than zero to minimize the number.
3. Remove remaining digits from the end if k is still greater than zero.
4. Remove leading zeros and return the final smallest number.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        // Step 1: Traverse the number string and maintain a monotonic increasing sequence using index manipulation
        int idx = 0; 

        for (char c : num) {

            // Step 2: Remove larger previous digits while k is greater than zero to minimize the number
            while (k > 0 && idx > 0 && num[idx - 1] > c) {
                idx--;
                k--;
            }

            num[idx++] = c;
        }

        // Step 3: Remove remaining digits from the end if k is still greater than zero
        idx -= k;

        // Step 4: Remove leading zeros and return the final smallest number
        int i = 0;

        while (i < idx && num[i] == '0')
            i++;

        num.erase(idx);
        num.erase(0, i);

        return num.empty() ? "0" : num;
    }
};
