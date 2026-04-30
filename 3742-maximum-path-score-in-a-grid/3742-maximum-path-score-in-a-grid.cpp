class Solution {
public:

    vector<vector<vector<int>>>dp;
    int n,m;

    int solution(int i,int j,int k,vector<vector<int>>&grid){
        if(i>=n || j>=m) return INT_MIN;
        if(k<0) return INT_MIN;

        int cost = (grid[i][j] == 0 ? 0 : 1);
        if (k < cost) return INT_MIN;

        if(i==n-1 && j==m-1) return (k>=0)?grid[i][j]:INT_MIN;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int right=solution(i+1,j,k-cost,grid);
        int bottom=solution(i,j+1,k-cost,grid);

        int best = max(bottom, right);

        if (best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = max(bottom, right) + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();

        dp.assign(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=solution(0,0,k,grid);
        return (ans==INT_MIN)?-1:ans;
    }
};