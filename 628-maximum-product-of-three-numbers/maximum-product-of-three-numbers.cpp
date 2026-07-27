class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Store the 3 biggest numbers
        int max1 = -1001, max2 = -1001, max3 = -1001;

        // Store the 2 smallest numbers
        int min1 = 1001, min2 = 1001;

        for (int num : nums) {

            // Update the three biggest numbers
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }

            // Update the two smallest numbers
            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        // Case 1: largest three numbers
        int product1 = max1 * max2 * max3;

        // Case 2: two negative numbers and one largest positive number
        int product2 = min1 * min2 * max1;

        return max(product1, product2);
    }
};