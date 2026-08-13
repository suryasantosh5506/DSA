class Solution {
public:

    vector<vector<int>>dp;
    int n;

    int solution(int i,int tgt,vector<int>&arr){
        if(tgt==0) return 0;
        if(i==n) return 1e8;
        if(tgt<0) return 1e8;
        if(dp[i][tgt]!=-1) return dp[i][tgt];

        int mini=INT_MAX;
        mini=min(mini,1+solution(i,tgt-arr[i],arr));
        mini=min(mini,solution(i+1,tgt,arr));
        return dp[i][tgt]=mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans=solution(0,amount,coins);
        return (ans>=1e8)?-1:ans;
    }
};