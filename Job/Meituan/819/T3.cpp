/*
小美定义一个 01 串的权值为：每次操作选择一位取反，使得相邻字符都不相等的最小操作次数。
例如，"10001"的权值是 1，因为只需要修改一次：对第三个字符取反即可。

现在小美拿到了一个 01 串，她希望你求出所有非空连续子串的权值之和，你能帮帮她吗？

输入描述: 一个仅包含'0'和'1'的字符串，长度不超过 2000。
输出描述: 所有非空子串的权值和。

1010101 或者 0101010
枚举求和
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    string s1, s2;
    s1 += '0';
    s2 += '1';
    for(int i=1; i<s.size(); i++){
        s1 += ((s1[i-1]-'0') ^ 1) + '0';
        s2 += ((s2[i-1]-'0') ^ 1) + '0';
    }
    vector<int> pre1(s.size()+1, 0);
    vector<int> pre2(s.size()+1, 0);
    for(int i=1; i<=s.size(); i++){
        pre1[i] = pre1[i-1];
        pre2[i] = pre2[i-1];
        if(s[i-1] != s1[i-1]){
            pre1[i]+=1;
        }
        if(s[i-1] != s2[i-1]){
            pre2[i]+=1;
        }
    }
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        for(int j=i+1; j<s.size(); j++){
            ans += min(pre1[j+1]-pre1[i], pre2[j+1]-pre2[i]);
        }
    }
    cout << ans << endl;
    return 0;
}