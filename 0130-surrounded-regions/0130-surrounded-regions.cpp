class Solution {
public:

    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j]='#';

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && board[nr][nc]=='O'){
                dfs(nr,nc,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        n=board.size();
        m=board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};