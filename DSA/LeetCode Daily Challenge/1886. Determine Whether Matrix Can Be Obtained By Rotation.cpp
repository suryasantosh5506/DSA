#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<4;i++){
            if(mat==target) return true;
            rotate(mat);
        }
        return false;
    }
};