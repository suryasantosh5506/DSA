class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        queue<vector<int>>q;
        for(auto &it:sources){
            grid[it[0]][it[1]]=it[2];
            q.push({it[0],it[1],it[2],0});
        }
        vector<int>dx={0,1,0,-1};
        vector<int>dy={-1,0,1,0};

        while(!q.empty()){
            int size=q.size();
            map<pair<int,int>, int> next;
            
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                int row=top[0];
                int col=top[1];
                int color=top[2];

                for(int k=0;k<4;k++){
                    int nr=row+dx[k];
                    int nc=col+dy[k];
                    if(isValid(nr,nc,n,m) && grid[nr][nc]==0){
                        next[{nr,nc}]=max(next[{nr,nc}],color);
                    }
                }
            }

            for(auto it:next){
                grid[it.first.first][it.first.second]=it.second;
                q.push({it.first.first,it.first.second,it.second});
            }
        }
        return grid;
    }
};