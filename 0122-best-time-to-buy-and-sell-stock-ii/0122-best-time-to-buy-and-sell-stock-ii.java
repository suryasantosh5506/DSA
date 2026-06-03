class Solution {

    int n;
    int dp[][];

    int solution(int i,int buy,int prices[]){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int ans=0;
        if(buy==0){
            ans=Math.max(ans,-prices[i]+solution(i+1,(buy==0)?1:0,prices));
            ans=Math.max(ans,solution(i+1,buy,prices));
        }else{
            ans=Math.max(ans,prices[i]+solution(i+1,(buy==0)?1:0,prices));
            ans=Math.max(ans,solution(i+1,buy,prices));
        }
        return dp[i][buy]=ans;
    }

    public int maxProfit(int[] prices) {
        n=prices.length;
        dp=new int[n][2];

        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        // buy->0
        // sell->1
        return solution(0,0,prices);
    }
}