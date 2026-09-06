class Solution {
public:

    int n,m;
    vector<int>dx={-1,0,1};
    vector<int>dy={1,1,1};
    vector<vector<int>>dp;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int solution(int i,int j,vector<vector<int>>& grid){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=0;k<3;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]>grid[i][j]){
                ans=max(ans,1+solution(nr,nc,grid));
            }
        }
        return dp[i][j]=ans;
    }

    int maxMoves(vector<vector<int>>& grid){
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,solution(i,0,grid));
        }
        return maxi;
    }
};