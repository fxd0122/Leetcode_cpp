/*
小红将n个珠子排成一排，然后将它们串起来，连接成了一串项链(连接后为一个环，即第一个和最后一个珠子也是相邻的)，
任意相邻两个珠子的距离为1。已知初始共有3个珠子是红色的，其余珠子是白色的。

小红拥有无穷的魔力，她可以对项链上的相邻两个珠子进行交险。小红希望用最小的交换次数，
使得红意两个红色的珠子的最小距离不小于k，你能帮小红求出最小的交换次数吗?

第一行输入一个正些数t，代表询问次数。
每行为一次询间，输出五个正整数n,k,a1,a2,a3,分别代表珠子总数量,要求的珠子距离，以及三个珠子的位置。
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<int> p(3);
vector<int> q(3);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, k, x, y, z;
        cin >> m >> k >> x >> y >> z;
        p[0] = x;
        p[1] = y;
        p[2] = z;
        sort(p.begin(), p.end());
        if (3ll * k > m)
        {
            cout << -1 << endl;
            continue;
        }
        q[0] = p[1] - p[0];
        q[1] = p[2] - p[1];
        q[2] = p[0] + m - p[2];
        sort(q.begin(), q.end());
        ll ans = 0;
        while (q[0] < k)
        {
            int now = min(k - q[0], q[2] - k);
            ans += now;
            q[2] -= now;
            q[0] += now;
            sort(q.begin(), q.end());
        }
        cout << ans << endl;
    }
    return 0;
}