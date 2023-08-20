class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> temp = intervals[0];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=intervals[i-1][1]){
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                temp[1] = intervals[i][1];
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};