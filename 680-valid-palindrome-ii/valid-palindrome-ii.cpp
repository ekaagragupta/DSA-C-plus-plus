class Solution {
public:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(const string &s) {
        int count = 0;
        int i=0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else if(isPalindrome(s, i, j-1)){
                count++;
                j--;
            }else if(isPalindrome(s, i+1, j)){
                count++;
                i++;
            }else{
                return false;
            }
        }
        return true;
        }

};
