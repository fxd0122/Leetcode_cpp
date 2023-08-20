class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ms;
        for(int i=0; i<s.size(); i++){
            if(ms.empty() || s[i]!=ms.top()){
                ms.push(s[i]);
            }
            else{
                ms.pop();
            }
        }
        string result = "";
        while (!ms.empty()) {
            result += ms.top();
            ms.pop();
        }
        reverse (result.begin(), result.end());
        return result;
    }
};