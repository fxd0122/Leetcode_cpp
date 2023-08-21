/*
小红最近迷上了纸牌。纸牌有黑桃(Spade)、红桃(Heart)、方块 (Diamond) 、梅花(Club) 四种花色，并且每张纸牌上面写了一个正整数。
小红拿到了许多牌，准备玩以下游戏: 每次操作在这堆牌中任取5张牌，计算这5张牌的分数，然后将其丢弃(丢弃的牌不可再次选取)。

为了简化，本题仅计算同花顺这一牌型:即取出的5张牌构成同花顺，则可以获得1分。其他牌型均不得分。
所谓同花顺，即五张牌花色相同，且排序后满足 ai+1=a（i+l）。 小红想知道，经过若干次操作后，自己最多可以得到多少分?

请注意，同一个牌型可能出现多次!
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct node{
    set<int> st;
    map<int, ll> cnt;
};
map<string, node> mp;
string cards[] = {"H","S","D","C"};


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        string card;
        cin >> x >> y >> card;
        mp[card].st.insert(x);
        mp[card].cnt[x] += y;
    }
    ll sum = 0;
    for (string now : cards){
        node tmp = mp[now];
        for (int from : tmp.st){
            ll cnt1 = tmp.cnt[from];
            for (int j = from + 1; j <= from + 4; j++){
                cnt1 = min(cnt1, tmp.cnt[j]);
            }
            sum += cnt1;
            for (int j = from + 1; j <= from + 4; j++) {
                tmp.cnt[j] -= cnt1;
            }
        }
    }
    cout << sum << endl;
    return 0;
}