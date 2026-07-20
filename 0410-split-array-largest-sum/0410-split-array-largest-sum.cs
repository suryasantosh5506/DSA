public class Solution {

    public bool possible(int mid,int[] nums,int k){
        int pages=0;
        int students=1;
        foreach(int x in nums){
            if(pages+x>mid){
                students++;
                pages=0;
            }
            pages+=x;
            if(students>k) return false;
        }
        return true;
    }

    public int SplitArray(int[] nums, int k) {
        int n=nums.Length;
        int low=nums.Max(),high=nums.Sum();
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
}