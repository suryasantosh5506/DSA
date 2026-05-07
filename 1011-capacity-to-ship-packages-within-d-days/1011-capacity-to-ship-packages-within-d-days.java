class Solution {

     boolean possible(int mid,int weights[], int days){
        int cap=0;
        int totaldays=1;

        for(int x:weights){
            if(cap+x>mid){
                totaldays++;
                cap=0;
            }
            cap+=x;
            if(totaldays>days) return false;
        }
        return true;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low=Arrays.stream(weights).max().getAsInt();
        int high=Arrays.stream(weights).sum();

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,weights,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}