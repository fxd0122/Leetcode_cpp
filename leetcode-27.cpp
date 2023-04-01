class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针
        int slow = 0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;

       /* int len = nums.size(); // 暴力解法
        for(int i=0;i<len;i++){
            if(nums[i]==val){
                for(int j=i;j<len-1;j++){
                    nums[j] = nums[j+1];
                }
                i--;
                len--;
            }
        }
        return len;*/
    }
};