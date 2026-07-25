public class Solution {
    public int MaxProduct(int n) {
        int fmaxi=int.MinValue,smaxi=int.MinValue;
        foreach(char ch in Convert.ToString(n)){
            int num=ch-'0';
            if(num>fmaxi){
                smaxi=fmaxi;
                fmaxi=num;
            }else if(num<=fmaxi && num>smaxi){
                smaxi=num;
            }
        }
        return fmaxi*smaxi;
    }
}