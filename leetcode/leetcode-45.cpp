class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int cur_cover = 0;
        int next_cover = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            next_cover = max(next_cover, i+nums[i]);
            if(i == cur_cover){
                cur_cover = next_cover;
                ans++;
                if(next_cover>=nums.size()-1) break;
            }
        }
        return ans;
    }
};