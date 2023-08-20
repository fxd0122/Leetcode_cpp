class Solution {
public:
    void GetNext(const string& s, int* next){
        int k=-1;
        next[0] = -1;
        for(int i=1; i<s.size(); i++){
            while(s[i]!=s[k+1]&&k>=0){
                k = next[k];
            }
            if(s[i]==s[k+1]){
                k++;
            }
            next[i] = k;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        GetNext(needle, next);
        // 匹配
        int k = -1;
        for(int i=0; i<haystack.size(); i++){
            while(haystack[i]!=needle[k+1]&&k>=0){
                k = next[k];
            }
            if(haystack[i] == needle[k+1]){
                k++;
            }
            if(k == (needle.size()-1)){
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
};