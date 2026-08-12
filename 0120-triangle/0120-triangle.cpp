class Solution {
public:

    vector<vector<int>>dp;
    int n;

    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.assign(n,vector<int>(n,-1));

        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int ans=INT_MAX;

                ans=min(ans,dp[i+1][j]);
                ans=min(ans,dp[i+1][j+1]);

                dp[i][j]=triangle[i][j]+ans;
            }
        }

        return dp[0][0];
    }
};