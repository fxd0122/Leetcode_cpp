class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int res1 = robrange(nums, 0, nums.size()-2);
        int res2 = robrange(nums, 1, nums.size()-1);
        return max(res1, res2);
    }

    int robrange(vector<int>& nums, int start, int end){
        vector<int> dp(nums.size(), 0);
        dp[1] = nums[start];
        int j = start+1;
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[j++]);
        }
        return dp[nums.size()-1];
    }
};