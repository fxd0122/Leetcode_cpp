#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    if(cin >> s){
        int hash[10] = {0};
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'0']++;
        }
        int ans = 0;
        for(int i=9; i>=0; i--){
            if(hash[i] == 0){
                continue;
            }
            int cnt = hash[i];
            while(cnt){
                ans = ans*10 + i;
                cnt--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}