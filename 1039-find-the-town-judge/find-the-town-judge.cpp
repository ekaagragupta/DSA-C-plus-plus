class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_degree(n+1,0);
        vector<int> out_degree(n+1,0);

        for(const auto relation:trust){
            int a=relation[0];
            out_degree[a]++;

            int b=relation[1];
            in_degree[b]++;
        }
        for(int i=1;i<=n;i++){
            if(in_degree[i]==n-1 && out_degree[i]==0){
                return i;
            }
        }
        return -1;
    }
};