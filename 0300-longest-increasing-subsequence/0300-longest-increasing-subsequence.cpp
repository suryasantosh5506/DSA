class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int prev,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];

        int maxi=0;
        if(prev==n+1 || nums[i]>nums[prev]){
            maxi=max(maxi,1+solution(i+1,i,nums));
        }
        maxi=max(maxi,solution(i+1,prev,nums));
        return dp[i][prev]=maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<int>(n+2,-1));
        return solution(0,n+1,nums);
    }
};