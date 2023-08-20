/* leetcode-468 */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isLegalIpv4Seg(const string& s){
        if(s.size()>3 || s.size()==0){
            return false;
        }
        if(s.size() > 1 && s[0] == '0'){
            return false;
        }
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0'&&s[i]<='9'){
                ans = ans*10 + (s[i]-'0');
            }else{
                return false;
            }
        }
        if(ans>=0 && ans <=255){
            return true;
        }else{
            return false;
        }
    }
    bool isIpv4(const string& ip){
        int lastSplitIndex = -1;
        int numSegs = 1;
        for(int i=0; i<ip.size(); i++){
            if(ip[i] != '.' && ip[i] != ':'){
                continue;
            }
            if(ip[i] == ':'){
                return false;
            }else{
                numSegs++;
                if(numSegs > 4){
                    return false;
                }
                int len = i-lastSplitIndex-1;
                if(isLegalIpv4Seg(ip.substr(lastSplitIndex+1, len))){
                    lastSplitIndex = i;
                }else{
                    return false;
                }
            }
        }
        if(isLegalIpv4Seg(ip.substr(lastSplitIndex+1, ip.size()))){
            if(numSegs != 4){
                return false;
            }
            return true;
        }else{
            return false;
        }
    }

    bool isLeaglChar(char c){
        if(c >= '0' && c <= '9'){
            return true;
        }
        if(c >= 'a' && c <= 'f'){
            return true;
        }
        if(c >= 'A' && c <= 'F'){
            return true;
        }
        return false;
    }

    bool isLegalIpv6Seg(const string& s){
        if(s.size()<1 || s.size()>4){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            if(isLeaglChar(s[i])){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isIpv6(const string& ip){
        int lastSplitIndex = -1;
        int numSegs = 1;
        for(int i=0; i<ip.size(); i++){
            if(ip[i]!='.' && ip[i]!=':'){
                continue;
            }
            if(ip[i] == '.'){
                return false;
            }else{
                numSegs++;
                if(numSegs>8){
                    return false;
                }
                int len = i - lastSplitIndex -1;
                if(isLegalIpv6Seg(ip.substr(lastSplitIndex+1, len))){
                    lastSplitIndex = i;
                }else{
                    return false;
                }
            }
        }
        if(isLegalIpv6Seg(ip.substr(lastSplitIndex+1, ip.size()))){
            if(numSegs != 8){
                return false;
            }
            return true;
        }else{
            return false;
        }
    }

    string validIPAddress(string queryIP) {
        if(queryIP.size()<7 || queryIP.size()>39){
            return "Neither";
        }
        if(isIpv4(queryIP)){
            return "IPv4";
        }
        if(isIpv6(queryIP)){
            return "IPv6";
        }
        return "Neither";
    }
};

int main(){
    string s;
    Solution solve;
    if(cin >> s){
        string ans = solve.validIPAddress(s);
        cout << ans;
    } 
    return 0;
}