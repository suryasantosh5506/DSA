class Solution {
public:

    vector<vector<int>>dp;

    int solution(int tgt,int n){
        if(tgt<0) return -1e8;
        if(tgt==0) return 1;
        if(dp[tgt][n]!=-1) return dp[tgt][n];

        int ans=1;

        for(int i=1;i<=n;i++){
            if(tgt-i>=0) ans=max(ans,i*solution(tgt-i,n));
        }
        return dp[tgt][n]=ans;
    }

    int integerBreak(int n) {
        dp.assign(n+1,vector<int>(n,-1));
        return solution(n,n-1);
    }
};