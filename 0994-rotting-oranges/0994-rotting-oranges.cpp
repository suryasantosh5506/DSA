class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();

        queue<vector<int>>q;
        // {row,col,time}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }else if(grid[i][j]==1) fresh++;
            }
        }

        vector<int>dx={0,1,0,-1};
        vector<int>dy={-1,0,1,0};

        int rotten=0;
        int ans=0;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int row=top[0];
            int col=top[1];
            int time=top[2];
            
            ans=max(ans,time);

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    rotten++;
                    grid[nr][nc]=2;
                    q.push({nr,nc,time+1});
                }
            }
        }
        return (rotten==fresh)?ans:-1;
    }
};