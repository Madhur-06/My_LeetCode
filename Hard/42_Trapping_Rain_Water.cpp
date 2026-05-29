/*
Problem: 42. Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/
Difficulty: Hard


Approach:
1. Build prefix maximum and suffix maximum arrays for each index.
2. Store the highest bar on the left side for every position.
3. Store the highest bar on the right side for every position.
4. Calculate trapped water at each index using the minimum of left and right maximum heights.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        vector<int> l_max;
        vector<int> r_max;

        // Step 1: Build prefix maximum and suffix maximum arrays for each index
        // Step 2: Store the highest bar on the left side for every position
        l_max.push_back(0);

        int l_mx=height[0];

        for(int i=1;i<n;i++){
            l_mx=max(l_mx,height[i-1]);
            l_max.push_back(l_mx);
        }

        // Step 3: Store the highest bar on the right side for every position
        r_max.push_back(0);

        int r_mx=height[n-1];

        for(int i=n-2;i>=0;i--){
            r_mx=max(r_mx,height[i+1]);
            r_max.push_back(r_mx);
        }

        reverse(r_max.begin(),r_max.end());

        int ans=0;

        // Step 4: Calculate trapped water at each index using the minimum of left and right maximum heights
        for(int i=0;i<n;i++){

            if(height[i]>min(l_max[i],r_max[i])){
                continue;
            }

            ans=ans+(min(l_max[i],r_max[i])-height[i]);
        }
        
       return ans;
    }
};
