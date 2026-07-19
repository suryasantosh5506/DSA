public class Solution {

    public bool possible(int mid,int[] nums,int threshold){
        int t=0;
        foreach(int x in nums){
            t+=(x+mid-1)/mid;
            if(t>threshold) return false;
        }
        return true;
    }

    public int SmallestDivisor(int[] nums, int threshold) {
        int n=nums.Length;
        int low=1,high=nums.Max();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,threshold)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
}