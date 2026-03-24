#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Brute {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll pro=1;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pro*=1ll*grid[i][j];
            }
        }

        vector<vector<int>>ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p=pro;
                p/=grid[i][j];
                ans[i][j]=p%12345;
            }
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        const int mod=12345;
        vector<int>arr;
        vector<vector<int>>ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.emplace_back(grid[i][j]%mod);
            }
        }

        n=arr.size();
        vector<ll>pre(n,1),suff(n,1);

        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]*arr[i-1]*1ll)%mod;
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=(suff[i+1]*arr[i+1]*1ll)%mod;
        }

        for(int i=0;i<n;i++){
            ans[i/m][i%m]=(pre[i]*suff[i]*1ll)%mod;
        }
        return ans;
    }
};