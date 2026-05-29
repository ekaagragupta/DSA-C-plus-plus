class Solution {
public:
    int trap(vector<int>& height) {

        // Pointer starting from the left end
        int left = 0;

        // Pointer starting from the right end
        int right = height.size() - 1;

        // Highest wall seen so far from the left side
        int leftMax = 0;

        // Highest wall seen so far from the right side
        int rightMax = 0;

        // Stores total trapped rain water
        int water = 0;

        // Process until both pointers meet
        while (left < right) {

            /*
                The amount of water above an index depends on:

                min(max wall on left, max wall on right)

                We always process the side having the smaller height
                because that side is guaranteed to be the limiting wall.

                Example:

                4           5
                |           |
                |   ? ? ?   |
                |___________|

                Since 4 < 5, the left side determines how much water
                can be stored, so we safely process the left pointer.
            */
            if (height[left] < height[right]) {

                /*
                    If current wall is greater than or equal to the
                    highest wall seen so far on the left,
                    update leftMax.

                    No water can be trapped on this index because
                    this wall itself becomes the new boundary.
                */
                if (height[left] >= leftMax)
                    leftMax = height[left];

                /*
                    Otherwise water can be trapped.

                    Water level = leftMax
                    Ground level = current height

                    Trapped water =
                    leftMax - current height
                */
                else
                    water += leftMax - height[left];

                // Move left pointer inward
                left++;
            }
            else {

                /*
                    Symmetric logic for the right side.

                    If current right wall becomes the highest wall
                    encountered from the right, update rightMax.
                */
                if (height[right] >= rightMax)
                    rightMax = height[right];

                /*
                    Otherwise water is trapped.

                    Water level = rightMax
                    Ground level = current height

                    Trapped water =
                    rightMax - current height
                */
                else
                    water += rightMax - height[right];

                // Move right pointer inward
                right--;
            }
        }

        // Return total trapped rain water
        return water;
    }
};