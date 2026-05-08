/*
Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: Easy


Approach:
1. Traverse the string and keep only alphanumeric characters in lowercase.
2. Initialize two pointers at the beginning and end of cleaned string.
3. Compare characters from both ends while moving pointers inward.
4. Return false if mismatch occurs, otherwise return true.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isPalindrome(string s) {

        string clean = "";

        // Step 1: Build cleaned lowercase string
        for(char c : s){
            if(isalnum(c)){
                clean += tolower(c);
            }
        }

        int start = 0;
        int end = clean.length() - 1;

        // Step 2 & 3: Compare characters using two pointers
        while(start <= end){

            if(clean[start] != clean[end]){
                return false;
            }

            start++;
            end--;
        }

        // Step 4: String is palindrome
        return true;
    }
};
