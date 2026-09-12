class Solution {
public:

    vector<vector<int>>visited;
    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void bfs(int row,int col,vector<vector<int>>& grid){
        visited.assign(n,vector<int>(m,0));
        queue<vector<int>>q;
        // {dist,row,col};
        q.push({1,row,col});
        visited[row][col]=1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int d=top[0];
            int r=top[1];
            int c=top[2];

            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(isValid(nr,nc) && !visited[nr][nc] && grid[nr][nc]!=0){
                    q.push({d+1,nr,nc});
                    visited[nr][nc]=d+1;
                }
            }
        }
    }

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        n=grid.size();
        m=grid[0].size();

        bfs(start[0],start[1],grid);
        vector<vector<int>>temp;
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] && grid[i][j]>=pricing[0] && grid[i][j]<=pricing[1]){
                    temp.push_back({visited[i][j],grid[i][j],i,j});
                }
            }
        }

        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            if(a[1]!=b[1]) return a[1]<b[1];
            if(a[2]!=b[2]) return a[2]<b[2];
            return a[3]<b[3];
        });

        for(int i=0;i<min(int(temp.size()),k);i++){
            ans.push_back({temp[i][2],temp[i][3]});
        }

        return ans;
    }
};