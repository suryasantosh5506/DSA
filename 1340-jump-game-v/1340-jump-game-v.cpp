class Solution {
public:

    int n;
    vector<int>dp;

    int solution(int i,vector<int>& arr, int d){
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int j=i+1;j<=i+d && j<n;j++){
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+solution(j,arr,d));
        }

        for(int j=i-1;j>=i-d && j>=0;j--){
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+solution(j,arr,d));
        }
        return dp[i]=ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.assign(n,-1);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,solution(i,arr,d));
        }
        return maxi;
    }
};