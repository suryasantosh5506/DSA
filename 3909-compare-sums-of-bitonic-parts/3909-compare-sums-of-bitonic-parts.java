class Solution {
    public int compareBitonicSums(int[] nums) {
        int maxi=Arrays.stream(nums).max().getAsInt();
        int k=0,n=nums.length;
        for(;k<n;k++){
            if(nums[k]==maxi) break;
        }
        long lsum=Arrays.stream(nums, 0, k+1).asLongStream().sum();
        long rsum=Arrays.stream(nums, k, n).asLongStream().sum();
        if(lsum==rsum) return -1;
        return (lsum>rsum)?0:1;
    }
}