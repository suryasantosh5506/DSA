// problem link:- https://leetcode.com/problems/count-good-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            unordered_set<int>st;
            int curror=0;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                curror|=nums[j];
                if(st.find(curror)!=st.end()) ans++;
            }
        }
        return ans;
    }
};