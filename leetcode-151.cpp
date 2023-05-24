class Solution {
public:
    string reverseWords(string s) {
        //去空格
        int slow=0, fast=0;
        for(; fast<s.size();fast++){
            if(s[fast]!=' '){
                if(slow!=0){
                    s[slow++] = ' ';
                }
                while(fast<s.size() && s[fast]!=' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        // 反转
        reverse(s.begin(), s.end());
        slow = 0;
        fast = 0;
        for(; fast<=s.size(); fast++){
            if(s[fast] == ' '|| fast == s.size()){
                int left = slow;
                int right = fast-1;
                while(left<right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                slow = fast+1;
            }
        }
        return s;
    }
};