class Solution {
public:

    vector<vector<string>>ans;
    vector<string>board;
    int n;

    bool canplace(int row,int col){
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        i=row;
        j=col;

        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }

        i=row;
        j=col;

        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        return true;
    }

    void solution(int col){
        if(col==n){
            ans.emplace_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(canplace(row,col)){
                board[row][col]='Q';
                solution(col+1);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n,string(n,'.'));
        this->n=n;
        solution(0);
        return ans;
    }
};