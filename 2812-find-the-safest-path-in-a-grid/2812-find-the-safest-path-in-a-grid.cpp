class Solution {
public:

    vector<vector<int>>distfromthief;
    int n,m;
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void markdist(vector<vector<int>>& grid){
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    distfromthief[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto top=q.front();
            int row=top[0];
            int col=top[1];
            int dist=top[2];

            q.pop();
            if(dist > distfromthief[row][col]) continue;

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc) && distfromthief[nr][nc]>1+dist){
                    distfromthief[nr][nc]=1+dist;
                    q.push({nr,nc,1+dist});
                }
            }
        }
    }

    int dijsktras(){
        vector<vector<int>>maxdistfromthief(n,vector<int>(m,INT_MIN));
        priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>>pq;

        pq.push({distfromthief[0][0],0,0});
        maxdistfromthief[0][0]=distfromthief[0][0];


        while(!pq.empty()){

            auto cur=pq.top();
            pq.pop();

            int safe=cur[0];
            int row=cur[1];
            int col=cur[2];

            if(safe<maxdistfromthief[row][col])
                continue;

            if(row==n-1 && col==m-1)
                return safe;

            for(int k=0;k<4;k++){

                int nr=row+dx[k];
                int nc=col+dy[k];

                if(!isValid(nr,nc))
                    continue;

                int newSafe=min(safe,distfromthief[nr][nc]);

                if(newSafe>maxdistfromthief[nr][nc]){
                    maxdistfromthief[nr][nc]=newSafe;
                    pq.push({newSafe,nr,nc});
                }
            }
        }
        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        distfromthief.resize(n,vector<int>(m,INT_MAX));
        markdist(grid);
        return dijsktras();
    }
};