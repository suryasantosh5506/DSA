class Solution {
public:

    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=0;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]==1){
                dfs(nr,nc,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};