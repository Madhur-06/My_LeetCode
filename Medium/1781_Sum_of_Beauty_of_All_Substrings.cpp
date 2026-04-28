/*
Problem: 1781. Sum of Beauty of All Substrings
Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
Difficulty: Medium


Approach:
1. Fix a starting index and initialize frequency array.
2. Expand substring by increasing ending index and update frequency.
3. For each substring, compute max and min frequency among characters.
4. Add (max - min) to total sum for all substrings.


Time Complexity: O(n^2 * 26)
Space Complexity: O(1)
*/

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        // Step 1 & 2: Generate all substrings and update frequency
        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};  

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                // Step 3: Calculate max and min frequency
                int max_f = 0, min_f = INT_MAX;
                for (int f:freq) {
                    if (f> 0) {
                        max_f = max(max_f, f);
                        min_f = min(min_f, f);
                    }
                }

                // Step 4: Add beauty to sum
                sum += (max_f - min_f);
            }
        }

        return sum;
    }
};
