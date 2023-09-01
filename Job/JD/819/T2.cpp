/*
小红准备买药治病。已知共有n种症状和m种药，第i种药可以治疗一些症状，但可能会导致一些副作用，添加一些新的症状。
小红依次服用了一些药，请你告诉小红，当她每次服用一副药时，当前还有多少症状？

输入描述:
    第一行输入一个正整数n，代表症状的数量
    第二行输入一个长应为n的01串，第i位是‘1’代表小红目前有第i个症状，第i位是‘0’代表没有该症状。
    第三行输入一个正整数m，代表药的数量
    接下来的2 * m行，每2行描述一副药:
    第一行输入一个长度为n的01串，代表该药能治疗的症状。’1‘代表可以治疗，‘0’代表不能治疗。
    第二行输入一个长度为n的01串，代表该药会产生的副作用。’1‘代表会产生该症状，’0‘代表不会产生。
    接下来的一行，输入一个正整数q，代表小红服用的药数量。
    接下来的q行，每行输入一个正整数u，代表小红服用了第u副药。
    1<=n<=20
    1<=m,q<=10^4
    1<=ai,u<=m
    保证每副药的副作用产生的症状和该药治疗的症状是不会重复的，即不会存在同一个位置的两个01串都是‘1’。
输出描述：
    输出q行，每行输入一个正整数，代表当前小红服用药后，身体有多少症状。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sick="";
int help(){
    int count=0;
    for(int i=0;i<sick.size();i++){
        if(sick[i]=='1'){
            count++;
        }
    }
    return count;
}
int main(){
    vector<int> res;
    int n;
    cin>>n;
    cin>>sick;
    int m;
    cin>>m;
    vector<vector<string>> medicine(m,vector<string>(2));
    for(int i=0;i<m;i++){
        string cure;
        cin>>cure;
        string reaction;
        cin>>reaction;
        medicine[i][0]=cure;
        medicine[i][1]=reaction;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int index;
        cin>>index;
        index--;
        for(int j=0;j<n;j++){
            if(medicine[index][0][j]=='1'){
                sick[j]='0';
            }
            if(medicine[index][1][j]=='1'){
                sick[j]='1';
            }
        }
        res.push_back(help());
    }
    for(auto n:res){
        cout<<n<<endl;
    }
    return 0;
}
