class Solution {
public:
    
    int n,m;
    vector<vector<int>>nodesinfirstpath;
    vector<vector<int>>visited;
    vector<int>dx={1,0};
    vector<int>dy={0,1};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool firstpath(int i,int j,vector<vector<int>>& grid){
        visited[i][j]=1;
        nodesinfirstpath.push_back({i,j});
        if(i==n-1 && j==m-1) return true;
        for(int k=0;k<2;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(isValid(nr,nc) && !visited[nr][nc] && grid[nr][nc]==1){
                if(firstpath(nr,nc,grid)) return true;
            }
        }
        nodesinfirstpath.pop_back();
        return false;
    }

    bool secondpath(int i,int j,vector<vector<int>>& grid){
        visited[i][j]=1;
        if(i==n-1 && j==m-1) return true;
        for(int k=0;k<2;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(isValid(nr,nc) && !visited[nr][nc] && grid[nr][nc]==1){
                if(secondpath(nr,nc,grid)) return true;
            }
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.assign(n,vector<int>(m,0));
        if(!firstpath(0,0,grid)) return true;
        visited.assign(n,vector<int>(m,0));
        for(auto &it:nodesinfirstpath){
            visited[it[0]][it[1]]=1;
        }
        visited[0][0]=0;
        visited[n-1][m-1]=0;

        if(secondpath(0,0,grid)) return false;
        return true;
    }
};