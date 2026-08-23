class Solution {
public:

    vector<vector<int>>dp;

    int solution(int i,int j,int sum,vector<int>&nums){
        if(j-i+1<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=0;
        if(nums[i]+nums[i+1]==sum) maxi=max(maxi,1+solution(i+2,j,sum,nums));
        if(nums[j]+nums[j-1]==sum) maxi=max(maxi,1+solution(i,j-2,sum,nums));
        if(nums[i]+nums[j]==sum) maxi=max(maxi,1+solution(i+1,j-1,sum,nums));
        return dp[i][j]=maxi;
    }

    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;

        dp.assign(n,vector<int>(n,-1));
        maxi=max(maxi,1+solution(2,n-1,nums[0]+nums[1],nums));

        dp.assign(n,vector<int>(n,-1));
        maxi=max(maxi,1+solution(0,n-3,nums[n-1]+nums[n-2],nums));

        dp.assign(n,vector<int>(n,-1));
        maxi=max(maxi,1+solution(1,n-2,nums[0]+nums[n-1],nums));

        return maxi;
    }
};