/*
美团商家的订单发起时，订单编号最开始从 1 开始，后续每发起一个订单，订单编号便在上一订单编号的基础上 +1。
为了防止订单号过大，商家还可以设置一个编号上限m，当订单编号超过m时，将又从 1 开始编号。
小美想知道，当订单编号上限为m时，第x个订单编号是多少？将有q次询问。

输入描述:
第一行输入一个整数q(1<=q<=50000)。接下来q行，每行两个整数m,x(11m,x110^9)。
输出描述:
q行，每行一个整数表示答案。
*/

#include <iostream>
using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int m, x;
        cin >> m >> x;
        if(x % m){
            cout << x % m << endl;
        }else{
            cout << m << endl;
        }
    }
    return 0;
}