class Solution {
public:

    int n,m;

    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();

        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        effort[0][0]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int eff=top[0];
            int row=top[1];
            int col=top[2];

            if(row==n-1 && col==m-1) return eff;

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc)){
                    int neweffort=abs(heights[nr][nc]-heights[row][col]);
                    neweffort=max(neweffort,effort[row][col]);
                    if(neweffort<effort[nr][nc]){
                        effort[nr][nc]=neweffort;
                        pq.push({effort[nr][nc],nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};