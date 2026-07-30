class Solution {
public:

    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool solution(int i,int j,int wi,string &word,vector<vector<char>>& board){
        if(wi==word.size()) return true;

        char ch=board[i][j];
        board[i][j]='#';

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && board[nr][nc]==word[wi]){
                if(solution(nr,nc,wi+1,word,board)) {
                    board[i][j]=ch;
                    return true;
                }
            }
        }
        board[i][j]=ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solution(i,j,1,word,board)) return true;
                }
            }
        }
        return false;
    }
};