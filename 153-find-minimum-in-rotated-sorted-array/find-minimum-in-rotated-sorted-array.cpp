

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            // if current part is already sorted
            // then first element is minimum
            if (nums[low] < nums[high]) {
                return nums[low];
            }

            int mid = low + (high - low) / 2;

            // minimum lies in right half
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }

            // minimum lies in left half including mid
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};