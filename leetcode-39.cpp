class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int cur_sum=0;
    void backtracking(vector<int>& candidates, int target, int index){
        if(cur_sum>=target){
            if(cur_sum == target) ans.push_back(path);
            return ;
        }
        for(int i=index; i<candidates.size(); i++){
            cur_sum+=candidates[i];
            if(cur_sum>target){
                cur_sum-=candidates[i];
                break;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            cur_sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
};