#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        
        // Max-heap to store pairs of {score, original_index}
        priority_queue<pair<int, int>> pq;
        
        // Populate the priority queue
        for (int i = 0; i < n; ++i) {
            pq.push({score[i], i});
        }
        
        int rank = 1;
        while (!pq.empty()) {
            // Retrieve the original index of the highest remaining score
            int original_index = pq.top().second;
            pq.pop();
            
            // Assign the appropriate rank string
            if (rank == 1) {
                ans[original_index] = "Gold Medal";
            } else if (rank == 2) {
                ans[original_index] = "Silver Medal";
            } else if (rank == 3) {
                ans[original_index] = "Bronze Medal";
            } else {
                ans[original_index] = to_string(rank);
            }
            rank++;
        }
        
        return ans;
    }
};