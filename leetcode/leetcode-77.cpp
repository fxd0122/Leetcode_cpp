class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void backtracking(int begin, int n, int k){
        if(k==0){
            ans.push_back(v);
            return;
        }
        for(int i=begin; i<=n; i++){
            v.push_back(i);
            backtracking(i+1, n, k-1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        // vector<vector<int>> ans;
        backtracking(1, n, k);
        return ans;
    }
};