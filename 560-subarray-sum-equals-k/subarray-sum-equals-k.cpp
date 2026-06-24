class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Empty prefix sum occurs once
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            // Update running prefix sum
            prefixSum += num;

            // We need a previous prefix such that:
            // prefixSum - previousPrefix = k
            int need = prefixSum - k;

            // If such prefix exists,
            // add all its occurrences
            if (mp.find(need) != mp.end()) {
                count += mp[need];
            }

            // Store current prefix sum
            mp[prefixSum]++;
        }

        return count;
    }
};