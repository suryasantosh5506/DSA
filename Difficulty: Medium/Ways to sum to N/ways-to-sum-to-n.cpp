class Solution {
  public:
  
    const int mod=1e9+7;
    vector<int>dp;
  
    int solution(int arr[],int n,int tgt){
        if(tgt==0) return 1;
        
        if(tgt<0) return 0;
        if(dp[tgt]!=-1) return dp[tgt];
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            cnt=(cnt+solution(arr,n,tgt-arr[i]))%mod;
        }
        
        return dp[tgt]=cnt%mod;
    }
    
    int countWays(int arr[], int n, int tgt) {
        // code here.
        dp.assign(tgt+1,-1);
        return solution(arr,n,tgt);
    }
};
