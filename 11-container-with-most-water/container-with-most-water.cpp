class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;                     // start pointer
        int right = height.size() - 1;    // end pointer
        int maxWater = 0;

        while(left < right){

            // width between two lines
            int width = right - left;

            // container height limited by smaller wall
            int h = min(height[left], height[right]);

            // current water area
            int area = width * h;

            // update maximum area
            maxWater = max(maxWater, area);

            // move pointer with smaller height
            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};