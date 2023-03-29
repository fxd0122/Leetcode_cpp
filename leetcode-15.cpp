class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int first = 0, second = 0, third = 0;
        for(first; first<length; first++){
            if(first>0&&nums[first-1]==nums[first]){
                continue;
            }
            int target = 0-nums[first];
            third = length - 1;
            second = first + 1;
            for(second; second<length; second++){
                if(second>first+1 && nums[second]==nums[second - 1]){
                    continue;
                }
                while(second<third && nums[second]+nums[third]>target){
                    third--;
                }
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }           
        }
        return ans;
    }
};