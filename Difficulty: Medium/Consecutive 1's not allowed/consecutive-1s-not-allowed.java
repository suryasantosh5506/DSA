class Solution {
    
    int dp[][];
    
    int solution(int i,int prev,int n){
        if(i==n) return 1;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans=0;
        if(prev==0){
            ans+=solution(i+1,1,n);
        }
        ans+=solution(i+1,0,n);
        
        return dp[i][prev]=ans;
    }
    
    int countStrings(int n) {
        // code here
        dp=new int[n+1][2];
        
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return solution(0,0,n);
    }
}
