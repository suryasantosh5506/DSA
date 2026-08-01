class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int left=0,right=n-1;
        int lmax=INT_MIN,rmax=INT_MIN;
        while(left<=right){
            if(lmax<=rmax){
                if(height[left]>lmax) lmax=height[left];
                ans+=(lmax-height[left]);
                left++;
            }else{
                if(height[right]>rmax) rmax=height[right];
                ans+=(rmax-height[right]);
                right--;
            }
        }
        return ans;
    }
};