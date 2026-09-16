/*
 alice = remove min element // 2 
// [5,4,3]
        bob = remove min element  // 3
      //  new queue qt
        bob = append // qt=[3]
        alice = append // qt=[3,2]
*/
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }

        return nums;
    }
};
