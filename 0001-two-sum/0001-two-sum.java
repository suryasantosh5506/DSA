class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mpp=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mpp.containsKey(req)){
                return new int[]{mpp.get(req),i};
            }
            mpp.put(nums[i],i);
        }
        return new int[]{-1,-1};
    }
}
