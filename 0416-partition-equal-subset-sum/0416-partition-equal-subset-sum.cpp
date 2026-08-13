class Solution {
public:

    vector<vector<int>>dp;
    int n;

    bool solution(int i,int tgt,vector<int>&nums){
        if(tgt==0) return true;
        if(i==n) return false;
        if(tgt<0) return false;
        if(dp[i][tgt]!=-1) return dp[i][tgt];

        return dp[i][tgt]=solution(i+1,tgt-nums[i],nums)||solution(i+1,tgt,nums);
        
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        n=nums.size();
        dp.assign(n,vector<int>((sum/2)+1,-1));
        return solution(0,sum/2,nums);
    }
};