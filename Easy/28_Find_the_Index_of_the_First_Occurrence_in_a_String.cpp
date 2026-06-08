/*
Problem: 28. Find the Index of the First Occurrence in a String
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Difficulty: Easy


Approach:
1. Handle the edge case when the needle string is empty.
2. Traverse all possible starting positions in the haystack.
3. Compare characters of the needle with the corresponding substring of the haystack.
4. Return the starting index when a complete match is found, otherwise return -1.


Time Complexity: O((n - m + 1) * m)
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n=haystack.size();
        int m=needle.size();

        // Step 1: Handle the edge case when the needle string is empty
        if(m==0){ 
            return 0;
        }

        // Step 2: Traverse all possible starting positions in the haystack
        for(int i=0;i<=n-m;i++) {

            int j;

            // Step 3: Compare characters of the needle with the corresponding substring of the haystack
            for (j=0;j<m;j++) {

                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }

            // Step 4: Return the starting index when a complete match is found, otherwise return -1
            if (j==m) {
                return i;
            }
        }

        return -1;
    }
};
