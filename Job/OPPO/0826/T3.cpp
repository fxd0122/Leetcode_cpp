#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getNext(vector<int>& next, string& s){
    for(int i=0; i<s.size(); i++){
        int j = i-1;
        while(j!=-1 && s[next[j]+1] != s[i]){
            j = next[j];
        } 
        if(j==-1){
            next[i] = -1;
        }else{
            next[i] = next[j]+1;
        }
    }
}

int main(){
    string s;
    cin >> s;
    string oppo = "oppo";
    int j=-1;
    vector<int> next(oppo.size());
    getNext(next, oppo);
    for(int i=0; i<s.size(); i++){
        while(j!=-1 && oppo[j+1]!=s[i]){
            j = next[j];
        }
        if(s[i] == oppo[j+1]){
            j++;
        }
        if(j == oppo.size()-1){
            cout << i-j << endl;
        }
    }
    return 0;
}