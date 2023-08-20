class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()==2 && s[0] == s[1]) return true;
        int next[s.size()];
        next[0] = -1;
        int k=-1;
        for(int i=1; i<s.size(); i++){
            while(s[i]!=s[k+1]&&k>=0){
                k = next[k];
            }
            if(s[i] == s[k+1]){
                k++;
            }
            next[i] = k;
        }
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};