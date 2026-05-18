/*
Problem: 735. Asteroid Collision
Link: https://leetcode.com/problems/asteroid-collision/
Difficulty: Medium


Approach:
1. Use a stack to keep track of asteroids moving safely without collision.
2. Traverse each asteroid and check collision conditions with the stack top.
3. Remove smaller asteroids or both asteroids if they are of equal size.
4. Push surviving asteroids into the stack and build the final result array.


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Step 1: Use a stack to keep track of asteroids moving safely without collision
        stack<int> stack;
        
        // Step 2: Traverse each asteroid and check collision conditions with the stack top
        for (int asteroid : asteroids) {

            bool alive = true;

            while (!stack.empty() && asteroid < 0 && stack.top() > 0) {

                // Step 3: Remove smaller asteroids or both asteroids if they are of equal size
                if (stack.top() < -asteroid) {
                    stack.pop();
                    continue;
                } 
                else if (stack.top() == -asteroid) {
                    stack.pop();
                }

                alive = false;
                break;
            }

            // Step 4: Push surviving asteroids into the stack and build the final result array
            if (alive) {
                stack.push(asteroid);
            }
        }
        
        vector<int> result(stack.size());

        for (int i = stack.size() - 1; i >= 0; --i) {
            result[i] = stack.top();
            stack.pop();
        }
        
        return result;
    }
};
