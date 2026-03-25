// problem link:- https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Brute {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<ll>rowsum(n);

        for(int i=0;i<n;i++){
            rowsum[i]=accumulate(grid[i].begin(),grid[i].end(),0ll);
        }

        ll sum=rowsum[0];
        for(int i=1;i<n;i++){
            if(sum==accumulate(rowsum.begin()+i,rowsum.end(),0ll)){
                return true;
            }
            sum+=rowsum[i];
        }

        vector<ll>colsum(m);

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                colsum[j] += grid[i][j];
            }
        }

        sum=colsum[0];
        for(int i=1;i<m;i++){
            if((ll)sum==accumulate(colsum.begin()+i,colsum.end(),0ll)){
                return true;
            }
            sum+=colsum[i];
        }

        return false;
    }
};

typedef long long ll;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<ll>rowsum(n);

        for(int i=0;i<n;i++){
            rowsum[i]=accumulate(grid[i].begin(),grid[i].end(),0ll);
        }

        ll total=accumulate(rowsum.begin(),rowsum.end(),0ll);
        ll sum=rowsum[0];
        for(int i=1;i<n;i++){
            if(sum==total-sum){
                return true;
            }
            sum+=rowsum[i];
        }

        vector<ll>colsum(m);

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                colsum[j] += grid[i][j];
            }
        }

        sum=colsum[0];
        total=accumulate(colsum.begin(),colsum.end(),0ll);

        for(int i=1;i<m;i++){
            if((ll)sum==total-sum){
                return true;
            }
            sum+=colsum[i];
        }

        return false;
    }
};