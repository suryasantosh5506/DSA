public class Solution {
    public string LargestOddNumber(string num) {
        int n=num.Length;
        for(int i=n-1;i>=0;i--){
            int numb=Convert.ToInt32(num[i]);
            if(numb%2==1) return num.Substring(0,i+1);
        }
        return "";
    }
}