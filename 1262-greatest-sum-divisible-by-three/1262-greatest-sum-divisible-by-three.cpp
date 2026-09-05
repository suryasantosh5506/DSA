class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int rem,vector<int>& nums){
        if(i==n) return (rem==0)?rem:-1e8;
        if(dp[i][rem]!=-1) return dp[i][rem];
        
        int ans=nums[i]+solution(i+1,(rem+nums[i])%3,nums);
        ans=max(ans,solution(i+1,rem,nums));

        return dp[i][rem]=ans;
    }

    int maxSumDivThree(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<int>(3,-1));
        return solution(0,0,nums);
    }
};