class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]-a[0] < b[1]-b[0];
        return a[0]<b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        for(int i=1; i<len; i++){
            if(intervals[i][0] < intervals[i-1][1]){
                ans++;
                intervals[i][1] = min(intervals[i][1], intervals[i-1][1]);
            }
        }
        return ans;
    }
};