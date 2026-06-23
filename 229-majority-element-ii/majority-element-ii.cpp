class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> map;

        for (auto n : nums) {
            map[n]++;
        }

        int n=nums.size();
        int size=n/3;

        for(auto m: map){
            if(m.second > size){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};