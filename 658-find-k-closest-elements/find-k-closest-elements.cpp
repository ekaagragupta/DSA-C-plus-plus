class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;

        // Keep removing elements until only k remain
        while (right - left + 1 > k) {

            int leftDist = abs(arr[left] - x);
            int rightDist = abs(arr[right] - x);

            if (leftDist > rightDist) {
                // Left element is farther, remove it
                left++;
            }
            else {
                // Right is farther OR distances are equal.
                // On equal distance, remove right because right value is larger.
                right--;
            }
        }

        // The remaining part from left to right is the answer
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};