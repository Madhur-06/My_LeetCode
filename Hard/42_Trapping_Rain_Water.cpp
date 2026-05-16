/*
Problem: 42. Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/
Difficulty: Hard


Approach:
1. Initialize two pointers at both ends along with leftMax and rightMax values.
2. Compare leftMax and rightMax to decide which side to process.
3. Update the maximum height seen so far from the chosen side.
4. Add the trapped water at each index using the difference between max height and current height.


Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {

        // Step 1: Initialize two pointers at both ends along with leftMax and rightMax values
        int left = 0;
        int right = height.size() - 1;

        int leftMax = height[left];
        int rightMax = height[right];

        int water = 0;

        while (left < right) {

            // Step 2: Compare leftMax and rightMax to decide which side to process
            if (leftMax < rightMax) {

                left++;

                // Step 3: Update the maximum height seen so far from the chosen side
                leftMax = max(leftMax, height[left]);

                // Step 4: Add the trapped water at each index using the difference between max height and current height
                water += leftMax - height[left];
            } 
            else {

                right--;

                // Step 3: Update the maximum height seen so far from the chosen side
                rightMax = max(rightMax, height[right]);

                // Step 4: Add the trapped water at each index using the difference between max height and current height
                water += rightMax - height[right];
            }
        }

        return water;        
    }
};
