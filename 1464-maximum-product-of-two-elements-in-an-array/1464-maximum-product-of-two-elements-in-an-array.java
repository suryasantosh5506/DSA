class Solution {
    public int maxProduct(int[] nums) {
        int fmaxi=Integer.MIN_VALUE,smaxi=Integer.MIN_VALUE;
        for(int x:nums){
            if(x>fmaxi){
                smaxi=fmaxi;
                fmaxi=x;
            }else if(x<=fmaxi && x>smaxi){
                smaxi=x;
            }
        }
        return (fmaxi-1)*(smaxi-1);
    }
}