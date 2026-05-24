/*
Problem: 402. Remove K Digits
Link: https://leetcode.com/problems/remove-k-digits/
Difficulty: Medium


Approach:
1. Traverse the number string and maintain a monotonic increasing result string.
2. Remove larger previous digits while k is greater than zero to minimize the number.
3. Remove remaining digits from the end if k is still greater than zero.
4. Remove leading zeros and return the final smallest number.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeKdigits(string nums, int k) {

        // Step 1: Traverse the number string and maintain a monotonic increasing result string
        if(nums.size()==k) return "0";

        string ans ="";

        for(int i=0;i<nums.size();i++){

            // Step 2: Remove larger previous digits while k is greater than zero to minimize the number
            while(!ans.empty() && k>0 && ans.back()>nums[i]){
                ans.pop_back();
                k--;
            }

            ans+=nums[i];
        }
    
        // Step 3: Remove remaining digits from the end if k is still greater than zero
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        // Step 4: Remove leading zeros and return the final smallest number
        int i = 0;

        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i); 
        
        return ans.empty() ? "0" : ans;
    }
};
