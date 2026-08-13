class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int tgt,vector<int>&coins){
        if(i==n) return tgt==0;
        if(tgt<0) return 0;
        if(dp[i][tgt]!=-1) return dp[i][tgt];

        return dp[i][tgt]=solution(i,tgt-coins[i],coins)+solution(i+1,tgt,coins);
    }

    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solution(0,amount,coins);
    }
};