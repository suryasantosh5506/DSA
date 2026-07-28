class Solution {
public:
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    int n,m;
    vector<vector<int>>visited;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int solution(int i,int j,vector<vector<int>>&grid){
        visited[i][j]=1;
        int ans=0;
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]!=0 && !visited[nr][nc]){
                ans=max(ans,solution(nr,nc,grid));
            }
        }
        visited[i][j]=0;
        return grid[i][j]+ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.assign(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solution(i,j,grid));
            }
        }
        return ans;
    }
};