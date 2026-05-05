class Solution {
    public int minimumSum(int[] nums) {
        int n=nums.length;
        int pre[]=new int[n];
        int suff[]=new int[n];

        pre[0]=nums[0];
        suff[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            pre[i]=Math.min(pre[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=Math.min(suff[i+1],nums[i]);
        }

        int ans=Integer.MAX_VALUE;

        for(int i=1;i<n-1;i++){
            if(pre[i-1]<nums[i] && suff[i+1]<nums[i]){
                ans=Math.min(ans,pre[i-1]+nums[i]+suff[i+1]);
            }
        }
        return (ans==Integer.MAX_VALUE)?-1:ans;
    }
}