class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        std::priority_queue<int> max_heap;
        for (int num : nums) {
            max_heap.push(num);
        }
        unordered_map<int, int> req;
        for (int i = 0; i < k; i++) {
            req[max_heap.top()]++;
            max_heap.pop();
        }
        vector<int> ans;
        for (int num : nums) {
            if (req[num] > 0) {
                ans.push_back(num);
                req[num]--;
            }
        }
        return ans;
    }
};