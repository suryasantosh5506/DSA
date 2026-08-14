class Solution {
public:

    vector<vector<int>>dp;

    int solution(int lower, int upper) {
        if(lower>=upper) return 0;
        if(dp[lower][upper]!=-1) return dp[lower][upper];
        int ans=INT_MAX;
        for(int i=lower;i<=upper;i++){
            int cost=i+max(solution(lower,i-1),solution(i+1,upper));
            ans=min(ans,cost);
        }
        return dp[lower][upper]=ans;
    }

    int getMoneyAmount(int n) {
        dp.assign(n+1,vector<int>(n+1,-1));
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            ans=min(ans,solution(1,n));
        }
        return ans;
    }
};