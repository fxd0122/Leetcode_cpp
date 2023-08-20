class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for(int i=0; i<len; i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        for(int i=0; i<len; i++){
            for(int j=target; j>=nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target] == target) return true;
        else return false;
    }
};