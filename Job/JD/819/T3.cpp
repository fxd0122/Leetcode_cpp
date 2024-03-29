/*
有一个n行m列的棋盘，有一些格子是障碍物不能通过。小红控制一个皇后在从左上角出发，每次移动她可以控制皇后进行以下三种方式中的一种:
1.向右移动若干个格子
2.向下移动若干个格子
3.向右下移动若干个格子。

用数学语言描述，当前的坐标在(x,y)时，每次移动可以到(x+k,y)或(x,y+k)或(x+k,y+k)其中k为任意正整数。移动的前提是，路径上没有障碍物。

小红想知道，皇后从左上角移动到右下角，最少要移动多少步?

输入描述:
    第一行输入两个正整数n和m，代表行数和列数。
    接下来的n行，每行输入一个长度m的字符串，用来表示棋盘。
    其中’.‘代表可以通过的位置，'*'代表障碍物。
    保证左上角和右下角都不是障碍物。
    1<=n,m<=2000。
输出描述:
    如果无法到达，请输出-1。
    否则输出一个整数，代表最少的移动次数。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define INF 10000000

int direct[3][2] = {0, 1, 1, 0, 1, 1};

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> chessboard(n);
    for(int i=0; i<n; i++){
        cin >> chessboard[i];
    }
    
    return 0;
}



