class Solution {
public:

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    void gameOfLife(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j]=board[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=0,dead=0;
                for(int k=0;k<8;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    
                    if(isValid(nr,nc)){
                        if(temp[nr][nc]==1) live++;
                        else dead++;
                    }
                }

                if(temp[i][j]==1 && live<2) board[i][j]=0;
                if(temp[i][j]==1 &&(live==2 || live==3)) board[i][j]=1;
                if(temp[i][j]==1 && live>3) board[i][j]=0;
                if(temp[i][j]==0 && live==3) board[i][j]=1;
            }
        }
    }
};