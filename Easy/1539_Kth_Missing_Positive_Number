/*
Problem: 1539. Kth Missing Positive Number
Link: https://leetcode.com/problems/kth-missing-positive-number/
Difficulty: Easy


Approach:
1. Traverse natural numbers starting from 1 while tracking index of given array.
2. Compare current number with array element to check if it is missing.
3. Decrement k whenever a missing number is found.
4. Return the number when k becomes 0.


Time Complexity: O(n + k)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int current = 1;

        // Step 1, 2 & 3: Traverse numbers and find missing ones
        while (k > 0) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                k--;
                if (k == 0) return current;
            }
            current++;
        }

        // Step 4: Return result
        return current;
    }
};
