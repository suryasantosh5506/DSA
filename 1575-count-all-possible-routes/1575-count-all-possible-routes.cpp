class Solution {
public:

    int n;
    const int mod=1e9+7;
    vector<vector<int>>dp;

    int solution(int i,vector<int>&locations,int finish,int fuel){
        if(dp[i][fuel]!=-1) return dp[i][fuel];
        int ans=(i==finish);
        for(int j=0;j<n;j++){
            int req=abs(locations[j]-locations[i]);
            if(j==i || fuel<req) continue;
            ans=(ans+solution(j,locations,finish,fuel-req))%mod;
        }

        return dp[i][fuel]=ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        dp.assign(n,vector<int>(fuel+1,-1));
        return solution(start,locations,finish,fuel);
    }
};