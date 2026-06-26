/*
Problem: 415. Add Strings
Link: https://leetcode.com/problems/add-strings/
Difficulty: Easy


Approach:
1. Traverse both strings from right to left while maintaining a carry.
2. Add the current digits from both strings along with the carry.
3. Store the current digit of the sum and update the carry.
4. Continue until all digits and carry are processed, then return the result.


Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
*/

class Solution {
public:
    string addStrings(string num1, string num2) {

        // Step 1: Traverse both strings from right to left while maintaining a carry
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        int carry = 0;
        string result = "";

        // Step 4: Continue until all digits and carry are processed, then return the result
        while (i >= 0 || j >= 0 || carry) {

            // Step 2: Add the current digits from both strings along with the carry
            int sum = carry;

            if (i >= 0)
                sum += num1[i--] - '0';

            if (j >= 0)
                sum += num2[j--] - '0';

            // Step 3: Store the current digit of the sum and update the carry
            result = char((sum % 10) + '0') + result;
            carry = sum / 10;
        }

        return result;
    }
};
