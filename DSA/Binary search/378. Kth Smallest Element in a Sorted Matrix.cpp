// problem link:- https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int upperBound(vector<int>&arr,int tgt){
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>tgt) high=mid-1;
            else low=mid+1;
        }
        return low;
    }

    int calculate(vector<vector<int>>& arr, int mid){
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upperBound(arr[i],mid);
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        while(low<=high){
            int mid=(low+high)/2;
            int cnt=calculate(matrix,mid);

            if(cnt<k)  low=mid+1;
            else high=mid-1;

        }
        return low;
    }
};
