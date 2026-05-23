/*
Problem: 735. Asteroid Collision
Link: https://leetcode.com/problems/asteroid-collision/
Difficulty: Medium


Approach:
1. Traverse asteroids from right to left and use a stack to track left-moving asteroids.
2. Push negative asteroids directly into the stack as they move left.
3. Resolve collisions for positive asteroids by comparing sizes with stack elements.
4. Store surviving asteroids and reverse the result to restore original order.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n=asteroids.size();

        // Step 1: Traverse asteroids from right to left and use a stack to track left-moving asteroids
        stack<int> st;

        vector<int> ans;

        for(int i=n-1;i>=0;i--){

            // Step 2: Push negative asteroids directly into the stack as they move left
            if(asteroids[i]<0){

                st.push(asteroids[i]);

            }
            else{

                bool destroyed=false;

                // Step 3: Resolve collisions for positive asteroids by comparing sizes with stack elements
                while(!st.empty()){
                    if(abs(st.top())>asteroids[i]){
                        break;
                    }
                    else if(abs(st.top())==asteroids[i]){
                        st.pop();
                        destroyed=true;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }

                if(st.empty()&&destroyed==false){
                    ans.push_back(asteroids[i]);
                }

            }
        }

        int sz=ans.size();

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        // Step 4: Store surviving asteroids and reverse the result to restore original order
        reverse(ans.begin()+sz,ans.end());
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
