class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) return 0;
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2*k, 0));
        for(int i=0; i<k; i++){
            dp[0][i*2] = -prices[0];
            dp[0][i*2 + 1] = 0;
        }
        for(int i=1; i<len; i++){
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
            for(int j=1; j<k; j++){
                dp[i][j*2] = max(dp[i-1][j*2], dp[i-1][j*2-1]-prices[i]);
                dp[i][j*2+1] = max(dp[i-1][j*2+1], prices[i]+dp[i-1][j*2]);
            }
        }
        return dp[len-1][2*k-1];
    }
};