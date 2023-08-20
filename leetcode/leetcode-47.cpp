class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
            while(i+1<nums.size()&&nums[i+1]==nums[i]&&used[i]==false) i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return ans;
    }
};