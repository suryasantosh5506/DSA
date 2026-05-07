class Solution {

     boolean possible(int mid,int[] nums, int threshold){
        int value=0;
        for(int x:nums){
            value+=(x+mid-1)/mid;
            if(value>threshold) return false;
        }
        return true;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int low=1,high=Arrays.stream(nums).max().getAsInt();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,threshold)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}