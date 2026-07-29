class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // Store (position, time)
        vector<pair<int, double>> cars;

        // Calculate time for every car
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort according to position
        sort(cars.begin(), cars.end());

        stack<pair<int, double>> ans;

        // Traverse from the car nearest to target
        for (int i = n - 1; i >= 0; i--) {

            // If stack is empty, first fleet
            if (ans.empty()) {
                ans.push(cars[i]);
            }

            // Current car reaches later than fleet ahead
            // so it forms a new fleet.
            else if (cars[i].second > ans.top().second) {
                ans.push(cars[i]);
            }

            // Else:
            // current car reaches earlier or same time,
            // so it joins the fleet ahead.
        }

        return ans.size();
    }
};