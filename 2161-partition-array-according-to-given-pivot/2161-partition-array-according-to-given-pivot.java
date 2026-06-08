class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n=nums.length;
        int i=0;
        int ans[]=new int[n];
        for(int x:nums){
            if(x<pivot) ans[i++]=x;
        }

        for(int x:nums){
            if(x==pivot) ans[i++]=x;
        }

        for(int x:nums){
            if(x>pivot) ans[i++]=x;
        }
        return ans;
    }
}