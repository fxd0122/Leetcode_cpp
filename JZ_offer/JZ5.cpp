class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        int numSpace = 0;
        int orginLen = s.size();
        for(int i=0; i<orginLen; i++){
            if(s[i] == ' ') numSpace++;
        }
        int newLen = orginLen + 2*numSpace;
        s.resize(newLen);
        for(int i=orginLen-1,j=newLen-1; i<j; i--, j--){
            if(s[i]!=' ') s[j] = s[i];
            else{
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j-=2;
            }
        }
        return s;
    }
};