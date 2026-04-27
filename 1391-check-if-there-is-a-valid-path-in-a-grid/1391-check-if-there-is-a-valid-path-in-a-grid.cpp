class Solution {
public:

    unordered_map<int,vector<vector<int>>>mpp;
    int n,m;
    vector<vector<int>>visited;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool solution(int i,int j,vector<vector<int>>&grid){
        if(i==n-1 && j==m-1) return true;
        if(i>=n && j>=m) return false;
        visited[i][j]=1;

        auto possibleDirections=mpp[grid[i][j]];

        for(auto direction:possibleDirections){
            int dx=i+direction[0];
            int dy=j+direction[1];

            if(!isValid(dx,dy) || visited[dx][dy]) continue;

            bool ok = false;
            for(auto back : mpp[grid[dx][dy]]){
                if(dx + back[0] == i && dy + back[1] == j){
                    ok = true;
                    break;
                }
            }

            if(ok && solution(dx,dy,grid)){
                return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        mpp[1]={{0,-1},{0,1}};
        mpp[2]={{1,0},{-1,0}};
        mpp[3]={{0,-1},{1,0}};
        mpp[4]={{0,1},{1,0}};
        mpp[5]={{0,-1},{-1,0}};
        mpp[6]={{0,1},{-1,0}};

        n=grid.size();
        m=grid[0].size();
        visited.assign(n,vector<int>(m,0));

        return solution(0,0,grid);
    }
};