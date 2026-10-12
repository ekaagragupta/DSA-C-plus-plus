class Solution {
public:
    void Combs(vector<vector<int>>& ans, vector<int>& temp, int i, int n, int k){
        if(i == n+1){
            if(temp.size() == k){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(i);
        Combs(ans, temp, i+1, n, k);
        temp.pop_back();
        Combs(ans, temp, i+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        Combs(ans, temp, 1, n, k);
        return ans;
    }
};