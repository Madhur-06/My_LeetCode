/*
Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: Easy


Approach:
1. Traverse the string and keep only alphanumeric characters in lowercase.
2. Store the cleaned characters at the beginning of the same string.
3. Use recursion with two pointers from both ends of the cleaned string.
4. If characters mismatch return false, otherwise continue until pointers cross.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isPalindrome_helper(string &s,int l,int r){

        // Step 3: Use recursion with two pointers from both ends of the cleaned string
        if(l>r){
            return true;
        }

        // Step 4: If characters mismatch return false, otherwise continue until pointers cross
        if(s[l]!=s[r]){
            return false;
        }

        return isPalindrome_helper(s,l+1,r-1);
    }


    bool isPalindrome(string s) {

        int n = s.size();
        
        int j=0;

        // Step 1: Traverse the string and keep only alphanumeric characters in lowercase
        // Step 2: Store the cleaned characters at the beginning of the same string
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                s[j] = tolower(s[i]);
                j++;
            }
        }
        n=j;

        return isPalindrome_helper(s,0,n-1);
    }
};
