class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5) return false;
        int nums[2] = {0, 0};
        int len = bills.size();
        for(int i=0; i<len; i++){
            if(bills[i] == 5) nums[0]++;
            else if(bills[i] == 10){
                if(nums[0] < 1) return false;
                else{
                    nums[1]++;
                    nums[0]--;
                }
            }
            else{
                if(nums[0]>=1 && nums[1]>=1){
                    nums[0]--;
                    nums[1]--;
                }
                else if(nums[1]<1 && nums[0]>=3){
                    nums[0] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};