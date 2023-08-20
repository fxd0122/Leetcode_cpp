class Solution {
public:
    int cur_sum=0;
    vector<int> path;
    vector<vector<int>> ans;

    void backtracking(int begin, int n, int k){
        if(k == 0){
            if(cur_sum == n) ans.push_back(path);
            return ;
        }
        for(int i=begin; i<=9; i++){
            cur_sum += i;
            if(cur_sum>n) {
                cur_sum -= i;
                break;
            }
            path.push_back(i);
            backtracking(i+1, n, k-1);
            cur_sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, n, k);
        return ans;
    }
};