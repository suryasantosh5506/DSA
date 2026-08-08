class Solution {
public:

    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]=='1'){
                dfs(nr,nc,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};