class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int i, j, ans;
        int sum=0;
        int len = nums.size();
        for(int i=0; i<(1<<len); i++){
            ans = 0;
            for(int j=0; j<len; j++){
                if(i & (1<<j)){
                    ans ^= nums[j];
                }
            }
            sum += ans;
        }
        return sum;
    }
};