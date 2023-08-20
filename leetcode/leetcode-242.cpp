class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int sum[26] = {0};
        for(int i=0; i<s.size(); i++){
            sum[s[i]-'a']++;
            sum[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(sum[i]!=0)
                return false;
        }
        return true;
    }
};