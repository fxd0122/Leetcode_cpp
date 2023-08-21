/*
在一个3* 3的棋盘上，小红和小紫正在玩“夹吃棋”。

所谓“夹吃棋”，即如果存在一个白子，它的两侧 (横向或者纵向)相邻都是黑子，则这个棋子将被“夹吃”，对于黑棋亦然。
如果一个棋盘的局面没有一方被夹吃，或者黑白双方都被对面夹吃，则认为是平局。如果只有一方夹吃了另一方，则认为夹吃方赢，被夹吃方输。
小红执黑棋，小紫执白棋，现在给定一个局面，请你判断当前棋局是谁获胜。

输入描述:
    第一行输入一个正整数t，代表询问的次数。
    接下来每组询问输入三行，，每行是一个长度为3的字符串，字符串仅由'o','.','*'组成。
    其中o代表白棋，*代表黑棋，.代表未放置棋子。
输出描述：
    小红获胜输出“kou”，小紫获胜输出“yukan”，平局输出“draw”。
*/

// #define mian main

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        vector<string> chessboard(3);
        cin >> chessboard[0] >> chessboard[1] >> chessboard[2];
        bool eatWhite = false;
        bool eatBlack = false;
        for(int m=0; m<3; m++){
            for(int n=0; n<3; n++){
                if(chessboard[m][n] == '.'){
                    continue;
                }else if(chessboard[m][n] == '*'){
                    if(
                        (m-1>=0&&m+1<3&&chessboard[m-1][n]=='o'&&chessboard[m+1][n]=='o') || 
                        (n-1>=0&&n+1<3&&chessboard[m][n-1]=='o'&&chessboard[m][n+1]=='o')
                    ){
                        eatBlack = true;
                    }
                }else{
                    if(
                        (m-1>=0&&m+1<3&&chessboard[m-1][n]=='*'&&chessboard[m+1][n]=='*') || 
                        (n-1>=0&&n+1<3&&chessboard[m][n-1]=='*'&&chessboard[m][n+1]=='*')
                    ){
                        eatWhite = true;
                    }
                }
            }
        }
        if(eatBlack ^ eatWhite){
            if(eatBlack){
                cout << "kou" << endl;
            }else if(eatWhite){
                cout << "yukan" << endl;
            }
        }else{
            cout << "draw" << endl;
        }
    }
    return 0;
}

