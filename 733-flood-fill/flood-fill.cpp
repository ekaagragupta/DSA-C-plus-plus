class Solution {
public:

void dfs(vector<vector<int>>& image, int r, int c, int ogc, int nc){
    if(r < 0 || c < 0 ||
   r >= image.size() ||       
   c >= image[0].size() ||   
   image[r][c] != ogc) {
    return;
}
    image[r][c]=nc;

    dfs(image,r-1,c,ogc,nc);
     dfs(image,r+1,c,ogc,nc);
      dfs(image,r,c-1,ogc,nc);
       dfs(image,r,c+1,ogc,nc);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor!=color){
            dfs(image,sr,sc,originalColor,color);
        }
        return image;
    }
};