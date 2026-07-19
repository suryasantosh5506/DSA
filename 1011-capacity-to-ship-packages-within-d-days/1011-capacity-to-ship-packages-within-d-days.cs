public class Solution {

    public bool possible(int mid,int[] weights,int days){
        int daysTaken=1;
        int cap=0;
        foreach(int x in weights){
            if(cap+x<=mid){
                cap+=x;
            }else{
                daysTaken++;
                cap=x;
            }

            if(daysTaken>days) return false;
        }
        return true;
    }

    public int ShipWithinDays(int[] weights, int days) {
        int n=weights.Length;
        int low=weights.Max(),high=weights.Sum();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,weights,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}