class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int cur_sum = 0;
    void backtracking(vector<int>& candidates, int target, int begin){
        if(cur_sum>=target){
            if(cur_sum == target) ans.push_back(path);
            return ;
        }
        for(int i=begin; i<candidates.size(); i++){
            cur_sum += candidates[i];
            if(cur_sum>target){
                cur_sum -= candidates[i];
                break;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, target, i+1);
            cur_sum-=candidates[i];
            path.pop_back();
            while(i+1<candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
};