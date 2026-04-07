/*
Problem: 67. Add Binary
Link: https://leetcode.com/problems/add-binary/
Difficulty: Easy


Approach:
1. Initialize pointers from end of both strings and a carry variable.
2. Traverse both strings from right to left while adding corresponding bits.
3. Compute sum, update result string with (sum % 2), and update carry.
4. Reverse the result string to get final binary sum.


Time Complexity: O(max(i, j))
Space Complexity: O(max(i, j))
*/

class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans;

        // Step 1, 2 & 3: Traverse and add bits with carry
        while (i >= 0 || j >= 0 || carry==1) {

            int sum = carry;

            if (i >= 0){ 
                sum = sum +  (a[i] - '0');
            }
            if (j >= 0){
                sum = sum + (b[j] - '0');
            }

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;

            i--;
            j--;
        }

        // Step 4: Reverse result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
