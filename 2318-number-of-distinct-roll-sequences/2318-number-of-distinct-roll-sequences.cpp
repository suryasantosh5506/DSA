class Solution {
public:

    vector<vector<vector<int>>>dp;
    const int mod=1e9+7;

    int solution(int i,int prev1,int prev2){
        if(i==0) return 1;
        if(dp[i][prev1][prev2]!=-1) return dp[i][prev1][prev2];

        int ans=0;
        for(int p=1;p<=6;p++){
            if(p==prev1 || p==prev2) continue;
            if(prev1!=0 && gcd(p,prev1)!=1) continue;
            ans=(ans+solution(i-1,p,prev1))%mod;
        }
        return dp[i][prev1][prev2]=ans;
    }

    int distinctSequences(int n) {
        dp.assign(n+1,
            vector<vector<int>>(7,
                vector<int>(7,-1)
            )
        );

        return solution(n,0,0);
    }
};