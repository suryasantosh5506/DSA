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
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<vector<int>>q;
        // {row,col,dist}
        q.push({0,0,1});
        dist[0][0]=1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int row=top[0];
            int col=top[1];
            int d=top[2];
            if(row==n-1 && col==m-1) return d;

            for(int k=0;k<8;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc) && dist[nr][nc]>1+d && grid[nr][nc]==0){
                    dist[nr][nc]=1+d;
                    q.push({nr,nc,1+d});
                }
            }
        }
        return -1;
    }
};