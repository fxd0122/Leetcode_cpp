class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int max_len = 1;
        vector<int> dp(len, 1);
        for(int i=1; i<len; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[j]+1, dp[i]);
            }
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};