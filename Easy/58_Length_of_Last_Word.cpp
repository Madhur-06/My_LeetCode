/*
Problem: 58. Length of Last Word
Link: https://leetcode.com/problems/length-of-last-word/
Difficulty: Easy


Approach:
1. Start from the end of the string and skip all trailing spaces.
2. Locate the last word by moving left from the last non-space character.
3. Count the characters belonging to the last word.
4. Return the length of the counted last word.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n=s.size();

        // Step 1: Start from the end of the string and skip all trailing spaces
        int id=n-1,ans=0;
        while(id!=-1&&s[id]==' '){
            id--;
        }

        // Step 2: Locate the last word by moving left from the last non-space character
        // Step 3: Count the characters belonging to the last word
        while(id!=-1&&s[id]!=' '){
            ans++;
            id--;
        }

        // Step 4: Return the length of the counted last word
        return ans;
    }
};
