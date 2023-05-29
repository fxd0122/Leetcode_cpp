class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // int len = nums.size();
        // int max_len = 1;
        // vector<int> dp(len, 1);
        // for(int i=1; i<len; i++){
        //     if(nums[i]>nums[i-1]) dp[i] = dp[i-1]+1;
        //     max_len = max(dp[i], max_len);
        // }
        // return max_len;
        int len = nums.size();
        int cur_len = 1;
        int max_len = 1;
        for(int i=1; i<len; i++){
            cur_len = nums[i]>nums[i-1]?cur_len+1:1;
            max_len = max(cur_len, max_len);
        }
        return max_len;
    }
};