class Solution {
public:
void backtrack(vector<int>&nums,int i,vector<vector<int>>&v,vector<int> ans){
    int n=nums.size();
    if(i==n){
        v.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    backtrack(nums,i+1,v,ans);
    ans.pop_back();
    backtrack(nums,i+1,v,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>ans;
        backtrack(nums,0,v,ans);
        return v;
    }
};