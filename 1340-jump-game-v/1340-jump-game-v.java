class Solution {

    int n;
    int dp[];

    int solution(int i,int arr[],int d){
        if(dp[i]!=-1) return dp[i];
        int ans=1;

        for(int j=i+1;j<n && j<=i+d;j++){
            if(arr[j]>=arr[i]) break;
            ans=Math.max(ans,1+solution(j,arr,d));
        }

        for(int j=i-1;j>=0 && j>=i-d;j--){
            if(arr[j]>=arr[i]) break;
            ans=Math.max(ans,1+solution(j,arr,d));
        }
        return dp[i]=ans;
    }

    public int maxJumps(int[] arr, int d) {
        n=arr.length;
        dp=new int[n];
        Arrays.fill(dp,-1);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=Math.max(maxi,solution(i,arr,d));
        }
        return maxi;
    }
}