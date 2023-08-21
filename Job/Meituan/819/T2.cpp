/*
小美有一个长度为n的数组，她想将这个数组进行求和，即 sum=a1+a2+...+an。
小美可以使用一次魔法（也可以不使用），将其中一个加号变成乘号，使得sum最大。求出最大的sum。

输入描述
第一行输入一个整数n。
第二行输入n个整数表示数组a。

1<=n<=10^5
11ai110^9
输出描述
输出一个整数表示答案。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 还得考虑int long long 
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    int ans = 0;
    ans = max(ans, sum);
    for(int i=1; i<n;  i++){
        int temp = sum-(nums[i]+nums[i-1])+(nums[i]*nums[i-1]);
        ans = max(temp, ans);
    }
    cout << ans << endl;
    return 0;
}

