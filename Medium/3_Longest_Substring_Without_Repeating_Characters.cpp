/*
Problem: 3. Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Difficulty: Medium


Approach:
1. Use sliding window with two pointers (left and right).
2. Expand window by adding characters if not present in set.
3. If duplicate found, shrink window from left until duplicate is removed.
4. Track and update maximum length of valid substring.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        
        // Step 1, 2 & 3: Sliding window traversal
        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        
        // Step 4: Return maximum length
        return maxLength;
    }
};
