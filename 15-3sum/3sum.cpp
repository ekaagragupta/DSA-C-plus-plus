class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // final answer array
        vector<vector<int>> ans;

        // sort the array first
        // why?
        // because two pointer only works on sorted array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // fixing one number at a time
        for(int i = 0; i < n; i++) {

            // skip duplicate fixed numbers
            // example:
            // if previous fixed number was -1
            // current is also -1
            // then same triplets will come again
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            // two pointers
            int left = i + 1;
            int right = n - 1;

            // now solve remaining as Two Sum
            while(left < right) {

                // current total sum
                int sum = nums[i] + nums[left] + nums[right];

                // if triplet found
                if(sum == 0) {

                    // store answer
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // move both pointers
                    left++;
                    right--;

                    // skip duplicate left values
                    // example:
                    // 0 0 0 0
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // skip duplicate right values
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                // if sum is too small
                // move left forward to increase sum
                else if(sum < 0) {
                    left++;
                }

                // if sum is too large
                // move right backward to decrease sum
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};