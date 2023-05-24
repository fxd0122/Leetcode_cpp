#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.size()>magazine.size()) return false;
    int r[26] = {0};
    int m[26] = {0};
    for(int i=0; i<ransomNote.size(); i++){
        r[ransomNote[i]-'a']++;
    }
    for(int i=0; i<magazine.size(); i++){
        m[magazine[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(r[i]!=0 && r[i]>m[i])
            return false;
    }
    return true;
}

int main(){
    string str1 = "aa";
    string str2 = "aab";
    bool t = canConstruct(str1, str2);
    cin.get();
}


