class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for (int stick : matchsticks) {
            sum += stick;
        }
        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if (matchsticks[0] > target) return false;

        vector<int> sq(4, 0);

        return backtrack(matchsticks, sq, 0, target);
    }

    bool backtrack(vector<int>& matchsticks, vector<int>& sq,
                   int idx, int target) {
        if (idx == matchsticks.size()) {
            return sq[0] == target &&
                   sq[1] == target &&
                   sq[2] == target &&
                   sq[3] == target;
        }

        int stick = matchsticks[idx];

        for (int i = 0; i < 4; i++) {

            if (sq[i] + stick > target) {
                continue;
            }

            sq[i] += stick;


            if (backtrack(matchsticks, sq, idx + 1, target)) {
                return true;
            }

            
            sq[i] -= stick;

        
            if (sq[i] == 0) {
                break;
            }
        }

        return false;
    }
};