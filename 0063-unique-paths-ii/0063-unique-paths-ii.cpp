class Solution {
public:

    int n,m;
    vector<vector<int>>dp;

    int solution(int i,int j,vector<vector<int>>&grid){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=solution(i,j-1,grid);
        int right=solution(i-1,j,grid);
        return dp[i][j]=left+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1) return 0;
        dp.assign(n,vector<int>(m,-1));
        return solution(n-1,m-1,obstacleGrid);
    }
};