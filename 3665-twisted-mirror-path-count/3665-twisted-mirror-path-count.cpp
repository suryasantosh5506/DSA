class Solution {
public:

    int n,m;
    const int mod=1e9+7;
    vector<vector<int>>dp;

    int solution(int i,int j,vector<vector<int>>&grid){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return grid[i][j]==0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
    
        int nr=i,nc=j+1;
        char dir='R';
        while(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
            if(dir=='R'){
                nr++;
                dir='D';
            }else{
                nc++;
                dir='R';
            }
        }

        ans=(ans+solution(nr,nc,grid))%mod;
        nr=i+1,nc=j,dir='D';

        while(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
            if(dir=='R'){
                nr++;
                dir='D';
            }else{
                nc++;
                dir='R';
            }
        }
        ans=(ans+solution(nr,nc,grid))%mod;
    
        return dp[i][j]=ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solution(0,0,grid);
    }
};