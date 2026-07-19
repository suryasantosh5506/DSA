public class Solution {

    public bool possible(int mid,int[] piles,int h){
        int time=0;
        foreach(int x in piles){
            time+=(x+mid-1)/mid;
            if(time>h) return false;
        }
        return true;
    }

    public int MinEatingSpeed(int[] piles, int h) {
        int n=piles.Length;
        int low=1,high=piles.Max();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,piles,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}