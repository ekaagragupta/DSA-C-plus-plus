class Solution {
public:
    void sink(vector<vector<char>>& grid,int i,int j,int n, int m){
        if(i==-1 || i==n || j==-1 || j==m || grid[i][j]=='0') return;
        grid[i][j]='0';
        sink(grid,i-1,j,n,m);
        sink(grid,i+1,j,n,m);
        sink(grid,i,j-1,n,m);
        sink(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    sink(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};