class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int hash[1001] = {0};
        for(int i=0; i<nums1.size(); i++){
            hash[nums1[i]] = 1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(hash[nums2[i]] == 1){
                if(find(ans.begin(), ans.end(), nums2[i])==ans.end())
                    ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};