class Solution {
public:
/*Boyer-Moore Voting Algorithm 
Interview Recognition
When you see:
majority element
appears more than n/2 times
Immediately think:
 Core Idea - Imagine election voting.
Example:
[2,2,1,1,1,2,2]
Every time:
Same candidate → gain vote
Different candidate → lose vote
Majority element can never be completely eliminated.
*/

    int majorityElement(vector<int>& nums) {

        // current majority candidate
        int candidate = 0;

        // vote count
        int count = 0;

        for(int num : nums) {

            // if no active candidate,
            // make current element candidate
            if(count == 0) {
                candidate = num;
            }

            // same candidate gets one vote
            if(num == candidate) {
                count++;
            }

            // different element cancels one vote
            else {
                count--;
            }
        }

        // surviving candidate is majority element
        return candidate;
    }
};