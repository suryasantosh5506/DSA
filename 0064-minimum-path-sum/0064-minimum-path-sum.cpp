class Solution {
public:

    vector<vector<int>>dp;
    int n,m;

    int solution(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e8;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=solution(i,j-1,grid);
        int right=solution(i-1,j,grid);
        return dp[i][j]=grid[i][j]+min(left,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        dp.assign(n,vector<int>(m,-1));
        return solution(n-1,m-1,grid);
    }
};