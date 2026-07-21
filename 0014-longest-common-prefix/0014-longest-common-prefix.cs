public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.Length;i++){
            int j=0;
            int n=strs[i].Length;
            while(j<prefix.Length && j<n && strs[i][j]==prefix[j]) j++;
            prefix=prefix.Substring(0,j);
        }
        return prefix;
    }
}