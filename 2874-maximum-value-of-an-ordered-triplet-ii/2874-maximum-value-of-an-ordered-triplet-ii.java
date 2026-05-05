class Solution {
    public long maximumTripletValue(int[] nums) {
        int n=nums.length;
        long pre[]=new long[n];
        long suff[]=new long[n];
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            pre[i]=Math.max(pre[i-1],(long)nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=Math.max(suff[i+1],(long)nums[i]);
        }
        long ans=Long.MIN_VALUE;

        for(int i=1;i<=n-2;i++){
            ans=Math.max(ans,(pre[i-1]-nums[i])*suff[i+1]);
        }
        return (ans<0)?0:ans;
    }
}