public class Solution {

    public bool possible(int mid,int[] arr,int m,int k){
        int boquets=0;
        int cnt=0;
        foreach(int x in arr){
            if(x<=mid) cnt++;
            else{
                boquets+=(cnt/k);
                cnt=0;
            }
            if(boquets>=m) return true;
        }
        boquets+=(cnt/k);
        return boquets>=m;
    }

    public int MinDays(int[] bloomDay, int m, int k) {
        int n=bloomDay.Length;
        if(1l*m*k>n) return -1;
        int low=bloomDay.Min(),high=bloomDay.Max();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,bloomDay,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}