typedef long long ll;
class Solution {
public:

    vector<int>costs;
    vector<ll>dp;
    int n;

    ll solution(int i){
        if(i==n) return 0ll;
        if(i>n) return (ll)1e18;
        if(dp[i]!=-1) return dp[i];

        ll mini=1e18;
        for(int j=i+1;j<=min(n,i+3);j++){
            ll cost=1ll*costs[j-1]+(j-i)*(j-i);
            mini=min(cost+solution(j),mini);
        }

        return dp[i]=mini;
    }

    int climbStairs(int n, vector<int>& costs) {
        this->n=n;
        dp.assign(n+1,-1);
        this->costs=costs;
        return solution(0);
    }
};