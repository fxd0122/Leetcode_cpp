class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        int num_2k = len / (2*k);
        int res = len % (2*k);
        for(int i=0; i<num_2k; i++){
            int first = 2*k*i;
            int second = 2*k*i + k -1;
            while(first < second){
                swap(s[first], s[second]);
                first++;
                second--;
            }
        }
        int first = 2*k*(num_2k);
        // int second = min(first+k-1, s.size()-1);
        int second = (first+k-1)>(s.size()-1)?(s.size()-1):first+k-1;
        while(first<second){
            swap(s[first], s[second]);
            first++;
            second--;
        }
        return s;
    }
};