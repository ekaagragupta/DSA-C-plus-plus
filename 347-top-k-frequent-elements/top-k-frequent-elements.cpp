class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count the freq of each element using hashmap
        unordered_map<int, int> map; // key= number , value = freq of occurence
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        vector<pair<int, int>> ans;
        for (auto m : map) {
            ans.push_back({m.second, m.first});
        }

        sort(ans.rbegin(), ans.rend());

        vector<int> finalAns;
        for (int i = 0; i < k; i++) {
            finalAns.push_back(ans[i].second);
        }
        return finalAns;
    }
};