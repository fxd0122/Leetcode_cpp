/*
模拟题：
    主要是确定温度怎么计算；温度用12位二进制数表示，最高位为符号位，低三位为小数点后的位数
注意：：
    c++中不同进制的输入！
*/

#include <iostream>

using namespace std;

int main(){
    unsigned int reg1, reg2, reg3;
    int alarm;
    cin >> hex >> reg1 >> hex >> reg2 >> hex >> reg3 >> dec >> alarm;
    unsigned int temp = 1;
    temp = temp << 8;
    int flag = reg1 & temp;
    
    return 0;
}