class Solution {

    boolean possible(int bananas,int h,int piles[]){
        int timetaken=0;
        for(int x:piles){
            timetaken+=(x+bananas-1)/bananas;
            if(timetaken>h) return false;
        }
        return true;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low=1,high=Arrays.stream(piles).max().getAsInt();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,h,piles)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}