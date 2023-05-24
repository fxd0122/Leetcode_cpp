class Solution {
public:

    vector<int> path;
    vector<vector<int>> ans;

    void backtracking(vector<int>& nums, int begin){
        ans.push_back(path);
        if(begin == nums.size()) return;
        for(int i=begin; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ans;
    }
};