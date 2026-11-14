class Solution {
public:
    int n,m;
    vector<vector<int>>visited;
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};

    bool isvalid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void dfs(int i,int j,vector<vector<int>>&land){
        visited[i][j]=1;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isvalid(nr,nc) && land[nr][nc]==1 && !visited[nr][nc]){
                dfs(nr,nc,land);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        visited.assign(n,vector<int>(m,0));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && land[i][j]==1){
                    dfs(i,j,land);
                    int r=i,c=j;
                    while(r<n && land[r][j]==1) r++;
                    while(c<m && land[i][c]==1) c++;
                    ans.push_back({i,j,r-1,c-1});
                }
            }
        }
        return ans;
    }
};