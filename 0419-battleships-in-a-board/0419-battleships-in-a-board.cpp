class Solution {
public:

    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void solution(int i,int j,vector<vector<char>>& board){
        board[i][j]='.';
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && board[nr][nc]=='X'){
                solution(nr,nc,board);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    cnt++;
                    solution(i,j,board);
                }
            }
        }
        return cnt;
    }
};