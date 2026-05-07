class Solution {
public:

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    vector<vector<int>>visited;

    int solution(int i,int j,vector<vector<char>>& maze){
        queue<vector<int>>q;
        // {row,col,steps} 
        q.push({i,j,0});
        visited[i][j]=1;
        int steps=-1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            if((top[0] != i || top[1] != j) &&
                (top[0] == 0 || top[1] == 0 ||
                top[0] == n-1 || top[1] == m-1)){
                    steps=top[2];
                    break;
            }

            for(int k=0;k<4;k++){
                int nr=top[0]+dx[k];
                int nc=top[1]+dy[k];

                if(isValid(nr,nc) && maze[nr][nc]!='+' && !visited[nr][nc]){
                    q.push({nr,nc,top[2]+1});
                    visited[nr][nc]=1;
                }
            }
        }
        return steps;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        visited.assign(n,vector<int>(m,0));
        return solution(entrance[0],entrance[1],maze);
    }
};