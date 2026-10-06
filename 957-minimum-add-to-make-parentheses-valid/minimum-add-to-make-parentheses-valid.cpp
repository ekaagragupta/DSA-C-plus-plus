class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int moves = 0;

        for(char c : s) {

            if(c == '(') {
                st.push(c);
            }
            else { // c == ')'

                if(!st.empty()) {
                    st.pop();       // match this ')' with '('
                }
                else {
                    moves++;        // need to insert '('
                }
            }
        }

        // Whatever '(' are left need ')' inserted
        moves += st.size();

        return moves;
    }
};