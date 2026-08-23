/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isallsame(int x,int y,vector<vector<int>>& grid,int n){
        int val=grid[x][y];
        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(grid[i][j]!=val)
                return false;
            }
        }
        return true;
    }
    Node* solve(int x,int y,vector<vector<int>>& grid,int n){
        if(isallsame(x,y,grid,n)){
            return new Node(grid[x][y],true);
        }
            Node* root=new Node(1,false);
            root->topLeft=solve(x,y,grid,n/2);
            root->topRight=solve(x,y+n/2,grid,n/2);
            root->bottomLeft=solve(x+n/2,y,grid,n/2);
            root->bottomRight=solve(x+n/2,y+n/2,grid,n/2);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(0,0,grid,grid.size());
    }
};