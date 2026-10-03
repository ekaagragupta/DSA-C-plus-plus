class Solution {
public:
int xorRecur(int i,int xorOfSubset,vector<int> &arr){
    if(i == arr.size()){
    return xorOfSubset;
}
    int subset1=xorRecur(i+1,xorOfSubset^arr[i], arr);

    int subset2=xorRecur(i+1,xorOfSubset, arr);

    return subset1+subset2;
}
    int subsetXORSum(vector<int>& nums) {
       return xorRecur(0, 0, nums); 
    }
};