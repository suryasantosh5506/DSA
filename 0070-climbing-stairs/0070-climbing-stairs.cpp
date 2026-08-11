class Solution {
public:

    vector<int>dp;

    int solution(int n){
        if(n==0) return 1;
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solution(n-1)+solution(n-2);
    }

    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solution(n);
    }
};