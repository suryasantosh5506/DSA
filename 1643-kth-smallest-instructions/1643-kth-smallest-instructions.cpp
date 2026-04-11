class Solution {
public:
    vector<vector<int>> dp;

    int countWays(int i, int j, vector<int>& dest) {
        if (i == dest[0] && j == dest[1]) return 1;
        if (i > dest[0] || j > dest[1]) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = countWays(i, j + 1, dest); 
        int down  = countWays(i + 1, j, dest); 

        return dp[i][j] = right + down;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int r = destination[0], c = destination[1];

        dp.assign(r + 1, vector<int>(c + 1, -1));

        string ans = "";
        int i = 0, j = 0;

        while (i < r || j < c) {
            if (j < c) {
                int cnt = countWays(i, j + 1, destination); // paths if we take 'H'

                if (k <= cnt) {
                    ans += 'H';
                    j++;
                } else {
                    ans += 'V';
                    k -= cnt;
                    i++;
                }
            } else {
                ans += 'V';
                i++;
            }
        }

        return ans;
    }
};