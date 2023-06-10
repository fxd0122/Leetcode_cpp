class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        if(len==0) return 0;
        int left=0, right=len-1;
        int ans=0;
        int leftmax=height[left], rightmax=height[right];
        while(left<right){
            if(height[left]<height[right]){
                left++;
                leftmax = max(leftmax, height[left]);
                ans+=max(min(leftmax, rightmax)-height[left], 0);
                
            }
            else{
                right--;
                rightmax=max(rightmax, height[right]);
                ans+=max(min(leftmax, rightmax)-height[right], 0);
                
            }
        }
        return ans;
    }
};