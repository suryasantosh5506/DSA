#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solution(int i,int tgt,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0){
            return (tgt==0)?0:-1e9;
        }

        if(tgt >= dp[0].size()) return -1e9;
        
        if(dp[i][tgt]!=-1) return dp[i][tgt];

        int take=1+solution(i-1,tgt^nums[i],nums,dp);
        int nottake=solution(i-1,tgt,nums,dp);

        return dp[i][tgt]=max(take,nottake);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        int maxVal = 0;
        for(int x : nums) maxVal = max(maxVal, x);

        int limit = 1;
        while(limit <= maxVal) limit <<= 1;

        vector<vector<int>> dp(n, vector<int>(limit, -1));

        int req = solution(n-1, target, nums, dp);

        if(req < 0) return -1;

        return n - req;
    }
};