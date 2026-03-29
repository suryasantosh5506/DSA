// problem link:- https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxVal=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxVal=max(maxVal,grid[i][j]);
            }
        }

        int max_xor=1;

        while(max_xor<=maxVal) max_xor<<=1;
        const int limit=1024;

        vector<vector<bitset<limit>>>dp(n,vector<bitset<limit>>(m));
        dp[0][0].set(grid[0][0]);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0) continue;

                bitset<limit>possible;

                if(i>0){
                    for(int r=0;r<limit;r++){
                        if(dp[i-1][j][r]) possible.set(r^grid[i][j]);
                    }
                }

                if(j>0){
                    for(int r=0;r<limit;r++){
                        if(dp[i][j-1][r]) possible.set(r^grid[i][j]);
                    }
                }
                dp[i][j]=possible;
            }
        }
        for(int i=0;i<limit;i++){
            if(dp[n-1][m-1][i]) return i;
        }

        return -1;
    }
};