class Solution {
public:

    int n;
    vector<int>dp;

    int solution(int i,vector<int>&prices){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=1e8;
        for(int j=1;j<=(i+2);j++){
            ans=min(ans,solution(i+j,prices));
        }

        return dp[i]=prices[i]+ans;
    }

    int minimumCoins(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,-1);
        return solution(0,prices);
    }
};