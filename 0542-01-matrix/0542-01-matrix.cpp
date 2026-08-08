class Solution {
public:

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();

        queue<vector<int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int>dx={0,1,0,-1};
        vector<int>dy={-1,0,1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int row=top[0];
            int col=top[1];
            int dist=top[2];

            for(int k=0;k<4;k++){
                int nr=row+dx[k];
                int nc=col+dy[k];

                if(isValid(nr,nc) && !visited[nr][nc] && mat[nr][nc]==1){
                    visited[nr][nc]=1;
                    mat[nr][nc]=dist+1;
                    q.push({nr,nc,dist+1});
                }
            }
        }
        return mat;
    }
};