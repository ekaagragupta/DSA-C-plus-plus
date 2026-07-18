#include <vector>
#include <string>
#include <stack>
#include <numeric>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> st;
        
        for (const std::string& op : operations) {
            if (op == "C") {
                // Invalidate the previous score
                if (!st.empty()) {
                    st.pop();
                }
            } else if (op == "D") {
                // Record a new score that is double the previous score
                if (!st.empty()) {
                    st.push(2 * st.top());
                }
            } else if (op == "+") {
                // Record a new score that is the sum of the previous two scores
                if (st.size() >= 2) {
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    
                    st.push(top1);       // Put the first one back
                    st.push(top1 + top2); // Push the new sum
                }
            } else {
                // It's an integer string, convert and push to stack
                st.push(std::stoi(op));
            }
        }
        
        // Sum all the scores remaining in the stack
        int totalSum = 0;
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        
        return totalSum;
    }
};