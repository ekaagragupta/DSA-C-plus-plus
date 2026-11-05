class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int gap = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int curr = arr1[i];
            bool found = false;

            for (int j = 0; j < arr2.size(); j++) {
                if (abs(curr - arr2[j]) <= d) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                gap++;
            }
        }

        return gap;
    }
};