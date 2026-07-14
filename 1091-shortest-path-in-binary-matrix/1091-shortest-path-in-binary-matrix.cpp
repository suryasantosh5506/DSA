class Solution {
public:

    int n,m;
    vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        queue<vector<int>>q;
        q.push({0,0,1});
        grid[0][0]=1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int row=top[0];
            int col=top[1];
            int dist=top[2];

            if(row==n-1 && col==m-1) return dist;

            for(int k=0;k<8;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc) && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc,dist+1});
                }
            }
        }
        return -1;
    }
};