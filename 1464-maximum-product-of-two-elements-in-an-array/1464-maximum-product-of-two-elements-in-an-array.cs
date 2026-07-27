public class Solution {
    public int MaxProduct(int[] nums) {
        int fmaxi=int.MinValue,smaxi=int.MinValue;
        foreach(int x in nums){
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