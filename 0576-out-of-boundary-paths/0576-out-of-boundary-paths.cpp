class Solution {
public:

    int n,m;
    const int mod=1e9+7;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};
    vector<vector<vector<int>>>dp;

    int solution(int i,int j,int moves){
        if(moves<0) return 0;
        if(i<0 || j<0 || i>=n || j>=m) return 1;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];

        int ans=0;
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            ans=(ans+solution(nr,nc,moves-1))%mod;
        }
        return dp[i][j][moves]=ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->n=m;
        this->m=n;
        dp.assign(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solution(startRow,startColumn,maxMove);
    }
};