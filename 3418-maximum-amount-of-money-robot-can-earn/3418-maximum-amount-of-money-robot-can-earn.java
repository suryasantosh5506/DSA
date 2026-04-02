class Solution {
    public int maximumAmount(int[][] coins) {
        int n = coins.length;
        int m = coins[0].length;
        int mini=(int)-1e9;

        int dp[][][]=new int[n][m][3];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int neutralize=0;neutralize<=2;neutralize++){
                    dp[i][j][neutralize]=mini;
                }
            }
        }

        for(int neutralize=0;neutralize<=2;neutralize++){
            if(coins[0][0]>=0) dp[0][0][neutralize]=coins[0][0];
            else{
                if(neutralize>0) dp[0][0][neutralize]=0;
                else dp[0][0][neutralize]=coins[0][0];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int neutralize : new int[] { 0, 1, 2 }) {
                    if(i == 0 && j == 0) continue;

                    int left =(j>0)?dp[i][j - 1][neutralize]:mini;
                    int top = (i>0)?dp[i - 1][j][neutralize]:mini;
                    int ans = mini;

                    if (coins[i][j] >= 0) {
                        ans = Math.max(ans, coins[i][j] + Math.max(left, top));
                    } else {
                        int take = coins[i][j] + Math.max(left, top);

                        int skip = mini;

                        if (neutralize > 0) {
                            skip=Math.max((j>0)?dp[i][j-1][neutralize-1]:mini,
                                (i>0)?dp[i-1][j][neutralize-1]:mini);
                        }

                        ans = Math.max(ans,Math.max(take, skip));
                    }

                    dp[i][j][neutralize] = ans;
                }
            }
        }

        return dp[n-1][m-1][2];
    }
}