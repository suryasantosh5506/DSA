class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer,List<Integer>>mpp=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(!mpp.containsKey(nums[i])){
                mpp.put(nums[i],new ArrayList<>());
            }
            mpp.get(nums[i]).add(i);
        }

        int ans=Integer.MAX_VALUE;
        for(int it:mpp.keySet()){
            List<Integer> v=mpp.get(it);
            if(v.size()<3) continue;
            int sum=0;
            for(int i=0;i+2<v.size();i++){
                sum=2*(v.get(i+2)-v.get(i));
                ans=Math.min(ans,sum);
            }
            
        }
        return (ans==Integer.MAX_VALUE)?-1:ans;
    }
}