/*
Problem: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
Difficulty: Easy


Approach:
1. Find the string with the minimum length since the prefix cannot exceed it.
2. Traverse characters of this smallest string one by one.
3. Compare the current character with the same index in all strings.
4. If a mismatch occurs, return the prefix formed so far.


Time Complexity: O(n * m)
n = number of strings, m = length of smallest string  
Space Complexity: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

        // Step 1: Find the string with minimum length
        int mn = strs[0].size(), mn_id = 0;
        for(int i = 1; i < n; i++){
            if(strs[i].size() < mn){
                mn = strs[i].size();
                mn_id = i;
            }
        }

        if(mn == 0){
            return "";
        }

        // Step 2 & 3: Compare characters of smallest string with all strings
        char curr_ch;
        for(int i = 0; i < mn; i++){
            curr_ch = strs[mn_id][i];
            for(int j = 0; j < n; j++){
                if(strs[j][i] != curr_ch){

                    // Step 4: Return prefix until mismatch
                    if(i == 0){
                        return "";
                    }
                    else{
                        return strs[mn_id].substr(0, i);
                    }
                }
            }
        }  

        return strs[mn_id];     
    }
};
