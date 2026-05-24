class Solution {
public:
    int maxProfit(vector<int>& prices) {
int sum=0;
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            // if stock price increases
            if(prices[i] > prices[i - 1]) {

                // add the profit
                profit = prices[i] - prices[i - 1];
                sum=sum+profit;
            }
        }

        return sum;
    }
};