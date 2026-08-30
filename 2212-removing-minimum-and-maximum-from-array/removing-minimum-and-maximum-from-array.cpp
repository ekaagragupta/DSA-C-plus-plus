class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int smallest = sorted[0];
        int largest = sorted[sorted.size() - 1];

        int count_smallest_gap = 0;
        int count_largest_gap = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == smallest) {
                count_smallest_gap = i;
            }

            if (nums[i] == largest) {
                count_largest_gap = i;
            }
        }

        int left = min(count_smallest_gap, count_largest_gap);
        int right = max(count_smallest_gap, count_largest_gap);

        int removeFromFront = right + 1;
        int removeFromBack = nums.size() - left;
        int removeBothSides = (left + 1) + (nums.size() - right);

        return min(removeFromFront, min(removeFromBack, removeBothSides));
    }
};