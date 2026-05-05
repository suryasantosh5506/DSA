class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=min(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=min(nums[i],suff[i+1]);
        }
        int ans=INT_MAX;

        for(int i=1;i<n-1;i++){
            if(pre[i-1]<nums[i] && suff[i+1]<nums[i]){
                ans=min(ans,pre[i-1]+nums[i]+suff[i+1]);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};