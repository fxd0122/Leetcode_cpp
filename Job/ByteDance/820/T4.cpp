/*
小红定义一个字符串的权值为:极长“连续段”的数量。所谓极长“连续段”，指尽可能长的一段字符全部相同的连续子串。
例如,"1100111"共有3个连续段:"11"、"00”和"111”，所以权值为 3。
现在小红拿到了一个01串，小红希望你帮她求出所有子串的权值之和。
*/

#include <iostream>
#include <string>
using namespace std;

using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size() != n){
        throw ;
    }
    ll pre = 1ll;
    ll ans = 1ll;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            pre = pre + 1ll;
        }else{
            pre = pre + ll(i) + 1ll;
        }
        ans += pre;
    }
    cout << ans << endl;
    return 0;
}