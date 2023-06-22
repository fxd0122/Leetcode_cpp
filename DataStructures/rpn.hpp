#ifndef DATASTRUCTRUES_RPN_H_
#define DATASTRUCTRUES_RPN_H_
// #pragma once

#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct node{
    double num;
    char op;
    bool flag;
};

class SimpleCal{
private:
    string str;
    stack<node> s;
    queue<node> q;
    map<char, int> priority;
public:
    SimpleCal(const string s1){
        str = s1;
        priority['+'] = 0;
        priority['-'] = 0;
        priority['*'] = 1;
        priority['/'] = 1;
        while(!s.empty()){
            s.pop();
        }
    }
    void mid2RPN(){
        
        double num;
        node temp;
        for(auto i=str.end(); i!=str.begin(); i--){
            if(*i == ' ') str.erase(i);
        }
        for(int i=0; i<str.size(); ){
            if(str[i] >= '0' && str[i] <= '9'){
                temp.flag = true;
                temp.num = str[i++] - '0';
                while(i<str.size() && str[i] >= '0' && str[i] <= '9'){
                    temp.num = temp.num * 10 + (str[i] - '0');
                    i++;
                }
                q.push(temp);
            }
            else{
                temp.flag = false;
                while(!s.empty() && priority[str[i]] <= priority[s.top().op]){ // 操作符优先级比栈顶小，出栈
                    q.push(s.top());
                    s.pop();
                }
                temp.op = str[i];
                s.push(temp);
                i++;
            }
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
    
    double calculate(){
        double temp1, temp2;
        node cur, temp;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.flag) s.push(cur);
            else{
                temp2 = s.top().num;
                s.pop();
                temp1 = s.top().num;
                s.pop();
                if(cur.op == '+') temp.num = temp1 + temp2;
                else if(cur.op == '-') temp.num = temp1 - temp2;
                else if(cur.op == '*') temp.num = temp1 * temp2;
                else if(cur.op == '/') temp.num = temp1 / temp2;
                temp.flag = true;
                s.push(temp);
            }
        }
        return s.top().num;
    }
    
    int getAns(){
        mid2RPN();
        return calculate();
    }
};

#endif