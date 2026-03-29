// problem link:- https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int one=-1,two=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==1) one=i;
            if(nums[i]==2) two=i;
            
            if(one!=-1 && two!=-1){
                ans=min(ans,abs(two-one));
            }
        }
        return ans==(INT_MAX)?-1:ans;
    }
};