class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size()==0 || k==0) return res;
        deque<int> d;
        for (int j=0, i=1-k; j<nums.size(); i++, j++) {
            if (i>0 && d.front()==nums[i-1]) d.pop_front();
            while (!d.empty() && d.back() < nums[j]) d.pop_back();
            d.push_back(nums[j]);
            if (i>=0) res.push_back(d.front());
        }
        return res;
    }
};