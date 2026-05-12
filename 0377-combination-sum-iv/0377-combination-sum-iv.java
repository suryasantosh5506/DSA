class Solution {

    int dp[];

    int solution(int tgt,int nums[]){
        if(tgt==0) return 1;
        if(tgt<0) return 0;
        if(dp[tgt]!=-1) return dp[tgt];

        int cnt=0;
        for(int i=0;i<nums.length;i++){
            cnt+=solution(tgt-nums[i],nums);
        }
        return dp[tgt]=cnt;
    }

    public int combinationSum4(int[] nums, int target) {
        dp=new int[target+1];
        Arrays.fill(dp,-1);
        return solution(target,nums);
    }
}