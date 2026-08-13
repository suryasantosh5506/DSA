class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int tgt,vector<int>&arr){
        if(i==n) return tgt==0;
        if(tgt<0) return 0;
        if(dp[i][tgt]!=-1) return dp[i][tgt];

        return dp[i][tgt]=solution(i+1,tgt-arr[i],arr)+solution(i+1,tgt,arr);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        n=nums.size();
        if(sum-target<0 || (sum-target)%2!=0) return 0;
        int tgt=(sum-target)/2;
        dp.assign(n,vector<int>(tgt+1,-1));
        return solution(0,tgt,nums);
    }
};