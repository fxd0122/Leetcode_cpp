class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> dp(prices.size(), 0);
        // int max_profit = 0;
        // for(int i=1; i<prices.size(); i++){
        //     int temp = prices[i] - prices[i-1];
        //     if(dp[i-1]<=0) dp[i] = temp;
        //     else dp[i] = temp+dp[i-1];
        //     if(max_profit < dp[i]) max_profit = dp[i];
        // }
        // return max_profit;
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};