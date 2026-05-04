class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer>mpp=new HashMap<>();
        int sum=0;
        mpp.put(sum,1);
        int ans=0;

        for(int x:nums){
            sum+=x;
            ans+=mpp.getOrDefault(sum-k,0);
            mpp.put(sum,mpp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}