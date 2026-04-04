class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[j]){
                int temp=nums[j+1];
                nums[j+1]=nums[i];
                nums[i]=temp;
                j++;
            }
        }
        return j+1;
    }
}