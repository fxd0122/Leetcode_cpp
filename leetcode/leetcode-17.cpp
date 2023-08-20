class Solution {
public:
    const string string_map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> ans;
    string s;

    void backtracking(string& digits, int index){
        if(index == digits.size()){
            ans.push_back(s);
            return ;
        }
        int cur = digits[index] - '0';
        for(int i=0; i<string_map[cur].size(); i++){
            s.push_back(string_map[cur][i]);
            backtracking(digits, index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        backtracking(digits, 0);
        return ans;
    }
};