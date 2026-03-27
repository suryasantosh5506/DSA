// problem link:- https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void leftshift(vector<int>&arr,int k){
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());
    }

    void rightshift(vector<int>&arr,int k){
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>original(mat.begin(),mat.end());

        k=k%m;
        

        for(int i=0;i<n;i++){
            if(i%2==0) leftshift(mat[i],k);
            else rightshift(mat[i],k);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=original[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};