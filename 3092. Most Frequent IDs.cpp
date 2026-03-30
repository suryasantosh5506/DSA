// problem link:- https://leetcode.com/problems/most-frequent-ids/description/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=freq.size();
        vector<ll>ans(n,0);
        priority_queue<pair<ll,ll>>pq;
        unordered_map<ll,ll>mpp;

        for(int i=0;i<n;i++){
           mpp[nums[i]]+=freq[i];
           pq.push({mpp[nums[i]],nums[i]});

            while(!pq.empty()){
                auto top=pq.top();
                pq.pop();

                ll val=top.second;
                ll f=top.first;

                if(mpp[val]==f){
                    ans[i]=f;
                    pq.push(top);
                    break;
                }
            }
        }
        return ans;
    }
};