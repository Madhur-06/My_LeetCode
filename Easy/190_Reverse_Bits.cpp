/*
Problem: 190. Reverse Bits
Link: https://leetcode.com/problems/reverse-bits/
Difficulty: Easy


Approach:
1. Convert the integer into a 32-bit binary representation using bitset.
2. Convert the bitset to string to manipulate individual bits easily.
3. Reverse the string to reverse the bit order.
4. Convert the reversed string back to integer using bitset and return.


Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int reverseBits(int n) {

        // Step 1: Convert integer to 32-bit bitset
        bitset<32> b(n);

        // Step 2: Convert bitset to string
        string s = b.to_string();

        // Step 3: Reverse the string
        reverse(s.begin(), s.end());

        // Step 4: Convert back to integer and return
        return bitset<32>(s).to_ulong();
    }
};
