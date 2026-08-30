class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        vector<vector<int>>visited(9,vector<int>(9,0));
        queue<vector<int>>q;
        q.push({source[0],source[1],0});
        visited[source[0]][source[1]] = 1;
        int n=8,m=8;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int row=top[0];
            int col=top[1];
            int moves=top[2];

            if(row==target[0] && col==target[1]) return moves;

            int i=row,j=col;

            while(i>=1 && j>=1){
                if(!visited[i][j]){    
                    q.push({i,j,moves+1});
                    visited[i][j]=1;
                }
                i--;j--;
            }

            i=row,j=col;

            while(i>=1 && j<=m){
                if(!visited[i][j]){    
                    q.push({i,j,moves+1});
                    visited[i][j]=1;
                }
                i--;j++;
            }

            i=row,j=col;

            while(i<=n && j>=1){
                if(!visited[i][j]){
                    q.push({i,j,moves+1});
                    visited[i][j]=1;
                }
                i++;j--;
            }

            i=row,j=col;

            while(i<=n && j<=m){
                if(!visited[i][j]){    
                    q.push({i,j,moves+1});
                    visited[i][j]=1;
                }
                i++;j++;
            }
        }
        return -1;
    }
};