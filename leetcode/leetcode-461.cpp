class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int ans = 0;
        while(temp){
            temp &= (temp - 1);
            ans++;
        }
        return ans;
    }
};