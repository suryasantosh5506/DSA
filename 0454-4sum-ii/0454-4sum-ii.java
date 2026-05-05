class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer,Integer>mpp=new HashMap<>();

        for(int x:nums1){
            for(int y:nums2){
                mpp.put(x+y,mpp.getOrDefault(x+y,0)+1);
            }
        }

        int ans=0;
        for(int x:nums3){
            for(int y:nums4){
                ans+=mpp.getOrDefault(-(x+y),0);
            }
        }
        return ans;
    }
}