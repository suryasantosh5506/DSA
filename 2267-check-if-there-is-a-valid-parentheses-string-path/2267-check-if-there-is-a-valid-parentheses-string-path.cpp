class Solution {
public:

    vector<int>dx={0,1};
    vector<int>dy={1,0};
    set<vector<int>>visited;
    // {i,j,balance};

    int n,m;

    bool isvalid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool solution(int i,int j,int balance,vector<vector<char>>&grid){
        if(visited.count({i,j,balance})) return false;
        visited.insert({i,j,balance});

        if(grid[i][j]=='(') balance++;
        else balance--;


        if(balance < 0) return false;

        if(i==n-1 && j==m-1){
            return balance==0;
        }

        for(int k=0;k<2;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(!isvalid(nr,nc)) continue;

            if(solution(nr,nc,balance,grid)){
                return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==')') return false;
        if((n + m - 1) % 2 != 0) return false;
        return solution(0,0,0,grid);
    }
};