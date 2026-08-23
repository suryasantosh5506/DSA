typedef long long ll;
class Solution {
public:

    const int mod=1e9+7;
    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};
    vector<vector<int>>dp;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    ll solution(int i,int j,vector<vector<int>>& grid){
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=0;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]>grid[i][j]){
                ans=(ans+1+solution(nr,nc,grid))%mod;
            }
        }
        return dp[i][j]=ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+1+solution(i,j,grid))%mod;
            }
        }
        return ans;
    }
};