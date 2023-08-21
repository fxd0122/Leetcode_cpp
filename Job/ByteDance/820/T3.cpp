/*
小红定义一个数组是好数组，当且仅当该数组中有且仅有一个元素和其他元素不同，剩余的所有元素相同。
例如，[2,2,2,5,2,2]是好数组。
小红拿到了一个数组，她可以进行若干次操作，每次操作可以使得一个元素加1或者减1。
小红希望用尽可能少的操作次数使得该数组变成好数组，你能帮帮她吗?

min S = |y-x1|+|y-x2|+...+|y-xn|
y 应该是中位数
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(vector<int>& nums, int target){
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans += abs(target-nums[i]);
    }
    return min((ans-abs(target-nums[0])), ans-abs(target-nums[nums.size()-1]));
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &n : nums){
        cin >> n;
    }
    sort(nums.begin(), nums.end());

    if(nums[0] == nums[n-1]){
        cout << 1 << endl;
    }
    
    if(n%2){
        int median = nums[n/2];
        int ans = process(nums, median);
        cout << ans << endl;
    }else{
        int median = (nums[n/2] + nums[n/2-1]) / 2;
        int ans = process(nums, median);
        cout << ans << endl;
    }
    return 0;
}