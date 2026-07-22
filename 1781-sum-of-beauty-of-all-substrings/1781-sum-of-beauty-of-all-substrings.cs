public class Solution {
    public int BeautySum(string s) {
        int ans=0;
        int n=s.Length;
        for(int i=0;i<n;i++){
            Dictionary<char,int>mpp=new();
            for(int j=i;j<n;j++){
                if(!mpp.ContainsKey(s[j])) mpp[s[j]]=1;
                else mpp[s[j]]++;
                int mini=int.MaxValue;
                int maxi=int.MinValue;
                foreach(char ch in mpp.Keys){
                    mini=Math.Min(mini,mpp[ch]);
                    maxi=Math.Max(maxi,mpp[ch]);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
}