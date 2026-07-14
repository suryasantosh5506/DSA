class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<int>dx={0,1,0,-1};
        vector<int>dy={-1,0,1,0};

        vector<vector<int>>effTracer(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        // {effort,r,c}

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int eff=top[0];
            int row=top[1];
            int col=top[2];

            if(row==n-1 && col==m-1)
                return eff;

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc,n,m)){
                    int newEff=abs(heights[nr][nc]-heights[row][col]);
                    newEff=max(eff,newEff);

                    if(newEff<effTracer[nr][nc]){
                        pq.push({newEff,nr,nc});
                        effTracer[nr][nc]=newEff;
                    }
                }
            }
        }
        return 0;
    }
};