class Solution {
    public int maxProduct(int n) {
        int fmaxi=Integer.MIN_VALUE,smaxi=Integer.MIN_VALUE;
        for(char ch:String.valueOf(n).toCharArray()){
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