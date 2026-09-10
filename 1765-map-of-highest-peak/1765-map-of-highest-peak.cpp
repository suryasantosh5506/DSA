class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>dx={0,1,0,-1};
        vector<int>dy={-1,0,1,0};
        queue<vector<int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({0,i,j});
                    visited[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }


        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int dist=top[0];
            int row=top[1];
            int col=top[2];

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc,n,m) && !visited[nr][nc]){
                    q.push({dist+1,nr,nc});
                    visited[nr][nc]=1;
                    ans[nr][nc]=dist+1;
                }
            }
        }
        return ans;
    }
};