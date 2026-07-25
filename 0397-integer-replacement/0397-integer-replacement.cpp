typedef long long ll;
class Solution {
public:

    unordered_map<ll,int>dp;

    int solution(ll n){
        if(n<=0) return 0;
        if(n==1) return 0;
        if(dp.count(n)) return dp[n];

        int mini=INT_MAX;
        if(n%2==0){
            mini=min(mini,1+solution(n/2));
        }else{
            mini=min(mini,1+solution(n-1));
            mini=min(mini,1+solution(n+1));
        }
        return dp[n]=mini;
    }

    int integerReplacement(int n) {
        return solution((ll)n);
    }
};