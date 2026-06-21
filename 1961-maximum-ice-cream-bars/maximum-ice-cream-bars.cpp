class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> count(maxCost + 1, 0);

        for (int cost : costs) {
            count[cost]++;
        }

        int bars = 0;

        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0) continue;

            long long totalCost = 1LL * cost * count[cost];

            if (coins >= totalCost) {
                bars += count[cost];
                coins -= totalCost;
            } else {
                bars += coins / cost;
                break;
            }
        }

        return bars;
    }
};