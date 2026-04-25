/*
Problem: 8. String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/
Difficulty: Medium


Approach:
1. Skip leading whitespaces and determine the sign of the number.
2. Traverse digits and build the number.
3. Apply the sign to the computed number.
4. Clamp the result within INT range and return.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i=0;

        // Step 1: Skip leading spaces
        while(s[i] == ' '){
            i++;
        }

        int sign=1;

        // Step 1: Determine sign
        if(s[i] == '-'){
            sign=-1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
    
        // Step 2: Build number from digits
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i]-'0');
            i++;
        }

        // Step 3: Apply sign
        num = num*sign;

        // Step 4: Clamp within integer range
        if(num > INT_MAX){
            num=INT_MAX;
        }
        if(num < INT_MIN) {
            num=INT_MIN;
        }

        return int(num);
    }
};
