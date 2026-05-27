/*
Problem: 239. Sliding Window Maximum
Link: https://leetcode.com/problems/sliding-window-maximum/
Difficulty: Hard


Approach:
1. Use a deque-like list to maintain elements in decreasing order for the current window.
2. Remove smaller elements from the back before inserting the current element.
3. Store the front element as the maximum when the window size becomes k.
4. Remove the outgoing element from the front if it matches the current maximum.


Time Complexity: O(n)
Space Complexity: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int left=0, right=0, n=nums.size(), max=INT_MIN;

        vector<int> result;

        // Step 1: Use a deque-like list to maintain elements in decreasing order for the current window
        list<int> l;

        while(right<n){

            // Step 2: Remove smaller elements from the back before inserting the current element
            while(l.size()>0 && l.back() < nums[right])
                l.pop_back();

            l.push_back(nums[right]);

            if((right-left+1)<k)
                right++;

            else if((right-left+1)==k){

                // Step 3: Store the front element as the maximum when the window size becomes k
                result.push_back(l.front());

                // Step 4: Remove the outgoing element from the front if it matches the current maximum
                if(nums[left]==l.front())
                    l.pop_front();

                left++;
                right++; 
            }
        }

        return result;
    }
};
