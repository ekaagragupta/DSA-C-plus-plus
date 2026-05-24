class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // opening brackets
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // closing brackets
            else {

                // stack empty means no matching opening bracket
                if(st.empty()) {
                    return false;
                }

                // check matching
                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                }

                // mismatch
                else {
                    return false;
                }
            }
        }

        // valid only if stack becomes empty
        return st.empty();
    }
};