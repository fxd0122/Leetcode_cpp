class Solution {
public:
    int GetSum(int num){
        int sum = 0;
        while(num!=0){
            int temp = num%10;
            sum += temp*temp;
            num = num/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        vector<int> hash;
        while(n!=1){
            n = GetSum(n);
            if(find(hash.begin(), hash.end(), n) != hash.end())
                return false;
            hash.push_back(n);
        }
        return true;
    }
};