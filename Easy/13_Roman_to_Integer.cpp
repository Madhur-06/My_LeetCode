/*
Problem: 13. Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/
Difficulty: Easy


Approach:
1. Traverse the string and get integer value of each Roman character.
2. Compare current value with next value to handle subtraction cases.
3. If current is smaller than next, subtract it; otherwise add it.
4. Accumulate the result and return final sum.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;

        // Step 1, 2 & 3: Traverse and process values
        for (int i = 0; i < s.size(); i++) {
            int cur = val(s[i]);

            if (i < s.size() - 1 && cur < val(s[i + 1]))
                sum -= cur;
            else
                sum += cur;
        }

        // Step 4: Return result
        return sum;
    }

private:
    int val(char c) {

        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;

    }
};
