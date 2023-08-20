#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.size()<4) return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int first=0, second=0, third=0, fourth=0;
    for(first; first<nums.size()-3; first++)
    {
        if(first>0 && nums[first-1]==nums[first])
            continue;
        second=first+1;
        for(second; second<nums.size()-2; second++){
            if(second>first+1 && nums[second-1] == nums[second])
                continue;
            third = second+1;
            fourth = nums.size()-1;
            int temp = target-(nums[first]+nums[second]);
            for(third; third<nums.size()-1; third++){
                if(third>second+1 && nums[third-1]==nums[third]) 
                    continue;
                while(third<fourth && nums[third] + nums[fourth] > temp) 
                    fourth--;
                if (fourth == third) {
                    break;
                }
                if(nums[third] + nums[fourth] == temp)
                    ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,0,-1,0,-2,2};
    int t = 0;
    auto res = fourSum(v, t);
    cin.get();
}
