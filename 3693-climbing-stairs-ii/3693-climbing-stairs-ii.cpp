typedef long long ll;
class Solution {
public:

    int n;
    vector<ll>dp;

    int solution(int i, vector<int>& costs){
        if(i==n) return 0;
        if(i>n) return 1e8;
        if(dp[i]!=-1) return dp[i];

        ll ans=1e18;
        for(int j=i+1;j<=min(n,i+3);j++){
            ll cost=1ll*(j-i)*(j-i)+costs[j-1];
            ans=min(ans,cost+solution(j,costs));
        }

        return dp[i]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        this->n=n;
        dp.assign(n+1,-1);
        return solution(0,costs);
    }
};