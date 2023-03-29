class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m1, m2;
        int ans = 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int temp = nums1[i] + nums2[j];
                if(m1.find(temp)==m1.end())
                    m1[temp] = 1;
                else
                    m1[temp]++;
                temp = nums3[i] + nums4[j];
                if(m2.find(temp)==m2.end())
                    m2[temp] = 1;
                else
                    m2[temp]++;
            }
        }
        for(auto kv : m1){
            int temp = kv.first;
            if(m2.find(-temp)!=m2.end()){
                ans += kv.second * m2[-temp];
            }
        }
        return ans;
    }
};