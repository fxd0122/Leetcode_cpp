class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]) max_profit+=(prices[i]-prices[i-1]);
        }
        return max_profit;
    }
};

// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int max_profit = 0;
        // for(int i=1; i<prices.size(); i++){
        //     if(prices[i]>prices[i-1]) max_profit+=(prices[i]-prices[i-1]);
        // }
        // return max_profit;
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0)); // dp[i][0] & dp[i][1]
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1; i<len; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }
        return dp[len-1][1];
    }
};