/*
Problem: Binary Search
Link: https://leetcode.com/problems/binary-search/
Difficulty: Easy


Approach:
1. Initialize two pointers: start (st) and end (ed).
2. Calculate the middle index and compare the key with the middle element.
3. If key is greater, search in the right half; if smaller, search in the left half.
4. Repeat until the element is found or the search space becomes empty.


Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int key) {

        int n = arr.size();

        // Step 1: Initialize start and end pointers
        int st = 0, ed = n - 1, mid;

        // Step 2, 3 & 4: Perform binary search
        while(st <= ed){
            mid = st + (ed - st) / 2;

            if(key > arr[mid]){
                st = mid + 1;
            }
            else if(key < arr[mid]){
                ed = mid - 1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
};
