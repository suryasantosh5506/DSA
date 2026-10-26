class Solution {
public:

    int n,m;
    int limit;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isvalid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int dfs(int i,int j,vector<vector<int>>&grid){
        int ans=grid[i][j];
        grid[i][j]=0;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(isvalid(nr,nc) && grid[nr][nc]!=0){
                ans=(ans+dfs(nr,nc,grid))%limit;
            }
        }
        return ans;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        limit=k;
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    if(dfs(i,j,grid)%k==0) ans++;
                }
            }
        }
        return ans;
    }
};