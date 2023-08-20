class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        for(int k=2; k<=n/2+1; k++){
            int temp = n / k;
            int flag = n % k;
            int cur = 1;
            for(int i=1; i<=k; i++){
                if(i<=flag) cur *= (temp+1);
                else cur *= temp;
            }
            ans = cur > ans ? cur : ans;
        }
        return ans;
    }
};