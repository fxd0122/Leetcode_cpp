class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }

        vector<int> ans;
        vector<pair<int, int>> f;
        for(auto& i:m){
            f.push_back(i);
        }
        sort(f.begin(), f.end(), [=](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;}); //lambda
        for(int i=0; i<k; i++){
            ans.push_back(f[i].first);
        }
        return ans;
    }
};