class Solution {
public:

    int n,m;
    vector<vector<int>>dp;
    int ans = INT_MIN;

    int solution(int i,int j,vector<vector<int>>&grid){
        if(i>=n || j>=m) return INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];

        int best = grid[i][j];

        if(j+1 < m){
            int right = solution(i,j+1,grid);
            ans = max(ans, right - grid[i][j]);
            best = max(best, right);
        }

        if(i+1 < n){
            int down = solution(i+1,j,grid);
            ans = max(ans, down - grid[i][j]);    
            best = max(best, down);
        }

        return dp[i][j] = best;
    }

    int maxScore(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solution(i,j,grid);
            }
        }
        return ans;
    }
};