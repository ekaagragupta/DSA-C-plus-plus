class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;

        // Sort the copied array
        sort(sorted.begin(), sorted.end());

        // Store rank of each unique number
        unordered_map<int, int> rank;
        int currRank = 1;

        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currRank++;
            }
        }

        // Replace original elements with their ranks
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};