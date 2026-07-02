class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MIN));

        pq.push({health - grid[0][0],0,0});
        dist[0][0]=health - grid[0][0];

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int row=top[1];
            int col=top[2];
            int remHealth=top[0];

            if(remHealth-grid[row][col]<0) continue;

            if(row==n-1 && col==m-1) return true;

            if(dist[row][col]>remHealth) continue;

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc,n,m)){
                    if(dist[nr][nc]<remHealth-grid[nr][nc]){
                        dist[nr][nc]=remHealth-grid[nr][nc];
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return false;
    }
};