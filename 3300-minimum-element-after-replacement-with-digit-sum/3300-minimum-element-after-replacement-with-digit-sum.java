class Solution {
    public int minElement(int[] nums) {
        int mini=Integer.MAX_VALUE;
        for(int x:nums){
            int sum=0;
            while(x!=0){
                sum+=x%10;
                x/=10;
            }
            mini=Math.min(mini,sum);
        }
        return mini;
    }
}