class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first+second);
            }
            else if(tokens[i] == "-"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first-second);
            }
            else if(tokens[i] == "*"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first*second);
            }
            else if(tokens[i] == "/"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(first/second);
            }
            else{
                s.push(StrToInt(tokens[i]));
            }
        }
        return s.top();
    }

    int StrToInt(const string& s){
        int size = s.size();
        int ans = 0;
        int flag = 1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '-'){
                flag = -1;
            }
            else{
                ans += (s[i]-'0')*pow(10, size-1-i);
            }
        }
        return flag*ans;
    }
};