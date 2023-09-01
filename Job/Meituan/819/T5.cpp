/*
小美拿到了一个数组，她每次可以进行如下操作：选择两个元素，一个加 1，另一个减 1。
小美希望若干次操作后，众数的出现次数尽可能多。你能帮她求出最小的操作次数吗？

众数定义：在一组数据中，出现次数最多的数据，是一组数据中的原数据，而不是相应的次数。
一组数据中的众数不止一个，如数据2、3、-1、2、1、3中，2、3都出现了两次，它们都是这组数据中的众数。

输入描述：第一行为一个正整数n，代表数组的大小。
        第二行输入n个正整数ai，代表小美拿到的数组。
输出描述：一个整数，代表最小的操作次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    if(sum % n == 0){
        int ans = 0;
        int temp = sum / n;
        for(int i=0; i<n; i++){
            ans += abs(temp-nums[i]);
        }
        cout << ans / 2 << endl;
    }else{
        int avg1 = (sum-nums[0])/(n-1);
        int remain1 = (sum-nums[0])%(n-1);
        if(remain1 >  (n-1)/2){
            avg1 += 1;
        }
        int x1=0, y1=0;
        for(int i=1; i<n; i++){
            if(nums[i]>=avg1){
                x1 += (nums[i]-avg1);
            }else{
                y1 += (avg1-nums[i]);
            }
        }
        int ans1 = min(x1, y1);

        int avg2 = (sum-nums[n-1])/(n-1);
        int remain2 = (sum-nums[n-1])%(n-1);
        if(remain2 >  (n-1)/2){
            avg2 += 1;
        }
        int x2=0, y2=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>=avg1){
                x2 += (nums[i]-avg2);
            }else{
                y2 += (avg2-nums[i]);
            }
        }
        int ans2 = min(x2, y2);
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
