// problem link:-https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2026-04-01

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<vector<int>,char>>arr;
        // {{pos,health,originalindex},direction}
        int n=positions.size();
        for(int i=0;i<n;i++){
            arr.push_back({{positions[i],healths[i],i},directions[i]});
        }

        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return a.first[0]<b.first[0];
        });

        stack<pair<vector<int>,char>>st;
        st.push(arr[0]);

        for(int i=1;i<n;i++){
            bool alive=true;
            
            while(!st.empty() && st.top().second == 'R' && arr[i].second == 'L'){
                if(st.top().first[1]<arr[i].first[1]){
                    st.pop();
                    arr[i].first[1]--;
                }else if(st.top().first[1]>arr[i].first[1]){
                    st.top().first[1]--;
                    alive=false;
                    break;
                }else{
                    st.pop();
                    alive=false;
                    break;
                }
            }
            if(alive) st.push(arr[i]);
        }

        vector<pair<vector<int>,char>>rem;
        while(!st.empty()){
            rem.emplace_back(st.top());
            st.pop();
        }

        sort(rem.begin(),rem.end(),[](auto &a,auto &b){
            return a.first[2]<b.first[2];
        });

        vector<int>ans;

        for(int i=0;i<rem.size();i++){
            ans.emplace_back(rem[i].first[1]);
        }
        return ans;
    }
};