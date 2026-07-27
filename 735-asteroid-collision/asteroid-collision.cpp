class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans; // Stores asteroids that are still alive

        for (int i = 0; i < asteroids.size(); i++) {

            // Positive asteroid moves right, so it cannot collide
            // with previous asteroids. Directly store it.
            if (asteroids[i] >= 0) {
                ans.push_back(asteroids[i]);
            }
            else {
                // Current asteroid moves left.
                // Remove smaller right-moving asteroids from the stack.
                while (!ans.empty() && ans.back() > 0 &&
                       -asteroids[i] > ans.back()) {
                    ans.pop_back();
                }

                // If both asteroids have same size,
                // both will explode.
                if (!ans.empty() && ans.back() > 0 &&
                    ans.back() == -asteroids[i]) {
                    ans.pop_back();
                    continue; // Current asteroid also exploded
                }

                // Push current asteroid when it survives:
                // - stack is empty, OR
                // - previous asteroid also moves left
                if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                }
            }
        }

        return ans;
    }
};