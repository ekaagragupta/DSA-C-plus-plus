class Solution {
public:
    void placequeen(vector<vector<string>>& ans,vector<string>& tans,int& n,vector<bool>& ld,vector<bool>& rd,vector<bool>& col,int i){
        if(i==n){
            ans.push_back(tans);
            return;
        }
        for(int j=0;j<n;j++){
            if(col[j] || ld[n-1+i-j] || rd[i+j]) continue;
            col[j]=true,ld[n-1+i-j]=true,rd[i+j]=true,tans[i][j]='Q';
            placequeen(ans,tans,n,ld,rd,col,i+1);
            col[j]=false,ld[n-1+i-j]=false,rd[i+j]=false,tans[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tans(n,string(n,'.'));
        vector<bool> ld(2*n-1,false),rd(2*n-1,false),col(n,false);
        placequeen(ans,tans,n,ld,rd,col,0);
        return ans;
    }
};