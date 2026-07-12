public class Solution {
    public int[] ArrayRankTransform(int[] arr) {
        int n=arr.Length;
        int[] ans=new int[n];
        SortedSet<int> st=new SortedSet<int>();
        foreach(int x in arr) st.Add(x);
        int rank=1;
        Dictionary<int,int>mpp=new Dictionary<int,int>();
        foreach(var x in st) mpp[x]=rank++;
        for(int i=0;i<n;i++){
            ans[i]=mpp[arr[i]];
        }
        return ans;
    }
}