/*
Problem: 1903. Largest Odd Number in String
Link: https://leetcode.com/problems/largest-odd-number-in-string/
Difficulty: Easy


Approach:
1. Traverse the string from the end to find the first odd digit.
2. Check if the current digit is odd using (digit % 2).
3. Once found, return the substring from start to that index.
4. If no odd digit exists, return an empty string.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string largestOddNumber(string num) {

        // Step 1: Traverse string from the end
        for(int i = num.size() - 1; i >= 0; i--){

            // Step 2: Check if current digit is odd
            if((num[i] - '0') % 2 != 0){

                // Step 3: Return substring till that index
                return num.substr(0, i + 1);
            }
        }
        
        // Step 4: No odd digit found
        return "";
    }
};
