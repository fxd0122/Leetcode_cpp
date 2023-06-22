#include <iostream>
#include <string>
#include "rpn.hpp"
using namespace std;

int main(){
    string str;
    while(getline(cin, str), str != "0"){
        SimpleCal cal = SimpleCal(str);
        cout << cal.getAns() << "\n";
    }

}