class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> candyVec(len, 1);
        // 从前向后
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // 从后向前
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < len; i++) result += candyVec[i];
        return result;
    }
};