/*
Problem: 3. Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Difficulty: Medium


Approach:
1. Use a sliding window with two pointers to track the current substring.
2. Store the last occurrence index of each character using a hash map.
3. Move the left pointer when a repeating character is found within the current window.
4. Update the maximum substring length after processing each character.


Time Complexity: O(n)
Space Complexity: O(min(n, charset))
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int maxLength = 0;

        // Step 2: Store the last occurrence index of each character using a hash map
        unordered_map<char, int> charMap;

        // Step 1: Use a sliding window with two pointers to track the current substring
        int left = 0;
        
        for (int right = 0; right < n; right++) {

            // Step 3: Move the left pointer when a repeating character is found within the current window
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {

                charMap[s[right]] = right;
            } 
            else {

                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }

            // Step 4: Update the maximum substring length after processing each character
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
