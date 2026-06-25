/*
Problem: 168. Excel Sheet Column Title
Link: https://leetcode.com/problems/excel-sheet-column-title/
Difficulty: Easy


Approach:
1. Repeatedly process the column number until it becomes zero.
2. Decrement the column number to convert it into zero-based indexing.
3. Find the current character using modulo 26 and append it to the answer.
4. Reverse the constructed string and return the final column title.


Time Complexity: O(log26 n)
Space Complexity: O(1)
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {

        string ans;

        // Step 1: Repeatedly process the column number until it becomes zero
        while (columnNumber > 0) {

            // Step 2: Decrement the column number to convert it into zero-based indexing
            columnNumber--;

            // Step 3: Find the current character using modulo 26 and append it to the answer
            int rem = columnNumber % 26;
            ans.push_back('A' + rem);

            columnNumber /= 26;
        }

        // Step 4: Reverse the constructed string and return the final column title
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
