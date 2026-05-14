class Solution {
  public:
  
    vector<int>dp;
  
    int solution(int i){
        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solution(i-1)+solution(i-2);
    }
  
    int countWays(int n) {
        // code here
        dp.resize(n+1,-1);
        return solution(n);
    }
};
