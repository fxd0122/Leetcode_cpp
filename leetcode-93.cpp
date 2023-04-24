class Solution {
public:
    // string s;
    vector<string> ans;
    void backTracking(string& s, int begin, int num_dot){
        if(num_dot == 3){
            if(isVaild(s, begin, s.size()-1)) ans.push_back(s);
            return ;
        }
        for(int i=begin; i<s.size(); i++){
            if(isVaild(s, begin, i)){
                s.insert(s.begin()+i+1, '.');
                backTracking(s, i+2, num_dot+1);
                s.erase(s.begin()+i+1);
            }
            else break;
        }
    }

    bool isVaild(string& s, int start, int end){
        if(start > end) return false;
        if((end-start)>=3) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i=start; i<=end; i++){
            if(s[i]>'9'||s[i]<'0') return false;
            num = num*10 + s[i]-'0';
            if(num>255) return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return ans;
        backTracking(s, 0, 0);
        return ans;
    }
};