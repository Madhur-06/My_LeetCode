/*
Problem: 2220. Minimum Bit Flips to Convert Number
Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Difficulty: Easy


Approach:
1. Compute XOR of start and goal to identify differing bits.
2. Use Brian Kernighan’s algorithm to count set bits in XOR result.
3. Each set bit represents one required flip.
4. Return the total count of flips.


Time Complexity: O(number of set bits)
Space Complexity: O(1)
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {

        // Step 1: Find differing bits using XOR
        int xor_val=(start^goal);

        int ans=0;

        // Step 2 & 3: Count set bits using Kernighan’s algorithm
        while(xor_val!=0){
            xor_val=xor_val&(xor_val-1);
            ans++;
        }

        // Step 4: Return total flips
        return ans;
    }
};
