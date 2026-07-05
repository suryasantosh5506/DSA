class Solution {
public:

    int n,m;
    vector<int>dx={-1,-1,0};
    vector<int>dy={0,-1,-1};
    const int mod=1e9+7;
    vector<vector<int>>scoreDp;
    vector<vector<int>>pathDp;
    int score=-1;
    int noofpaths=0;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int maxScore(int i,int j,vector<string>& board){
        if(i==0 && j==0) return scoreDp[0][0] =0;
        if(i<0 || j<0) return INT_MIN;
        if(scoreDp[i][j]!=-1) return scoreDp[i][j];

        int ans=INT_MIN;
        for(int k=0;k<3;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(isValid(nr,nc) && board[nr][nc]!='X'){
                int maxi=maxScore(nr,nc,board);
                int val=0;
                if(board[i][j]!='S' && board[i][j]!='E') val=(board[i][j]-'0');
                if(maxi!=INT_MIN) ans=max(ans,maxi+val);
            }
        }
        return scoreDp[i][j]=ans;
    }

    int paths(int i,int j,vector<string>& board){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(pathDp[i][j]!=-1) return pathDp[i][j];

        int val=0;
        int ways=0;
        if(board[i][j]!='S' && board[i][j]!='E') val=board[i][j]-'0';

        for(int k=0;k<3;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(!isValid(nr,nc)) continue;
            if(board[nr][nc]=='X') continue;
            if(scoreDp[nr][nc]==INT_MIN) continue;
            if(scoreDp[nr][nc]==-1) continue;

            if(scoreDp[nr][nc]+val==scoreDp[i][j]){
                ways=(ways+paths(nr,nc,board))%mod;
            }
        }
        return pathDp[i][j]=ways;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        scoreDp.assign(n,vector<int>(m,-1));
        pathDp.assign(n,vector<int>(m,-1));
        score=maxScore(n-1,m-1,board);
        if (score == INT_MIN)
            return {0, 0};
        noofpaths=paths(n-1,m-1,board);
        return {score,noofpaths};
    }
};