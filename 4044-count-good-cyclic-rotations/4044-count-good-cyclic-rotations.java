class Solution {
    public int countGoodRotations(int[] nums) {
        int n=nums.length;
        long lsum=0,rsum=0;
        int ans=0;
        for(int i=0;i<n/2;i++) lsum+=nums[i];
        for(int i=n/2;i<n;i++) rsum+=nums[i];

        for(int i=0;i<n;i++){
            if(lsum>rsum) ans++;
            lsum-=nums[i];
            rsum+=nums[i];

            rsum-=nums[((n/2)+i)%n];
            lsum+=nums[((n/2)+i)%n];
        }
        return ans;
    }
}