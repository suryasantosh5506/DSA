class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(3, -1e9)));

        for(int neutralize=0;neutralize<=2;neutralize++){
            if(coins[0][0]>=0) dp[0][0][neutralize]=coins[0][0];
            else{
                if(neutralize>0) dp[0][0][neutralize]=0;
                else dp[0][0][neutralize]=coins[0][0];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int neutralize : { 0, 1, 2 }) {
                    if(i == 0 && j == 0) continue;

                    int left =(j>0)?dp[i][j - 1][neutralize]:-1e9;
                    int top = (i>0)?dp[i - 1][j][neutralize]:-1e9;
                    int ans = -1e9;

                    if (coins[i][j] >= 0) {
                        ans = max(ans, coins[i][j] + max(left, top));
                    } else {
                        int take = coins[i][j] + max(left, top);

                        int skip = -1e9;

                        if (neutralize > 0) {
                            skip=max((j>0)?dp[i][j-1][neutralize-1]:-1e9,
                                (i>0)?dp[i-1][j][neutralize-1]:-1e9);
                        }

                        ans = max({ans, take, skip});
                    }

                    dp[i][j][neutralize] = ans;
                }
            }
        }

        return dp[n-1][m-1][2];
    }
};