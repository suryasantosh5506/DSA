// problem link:- https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>graph(V);
        for(auto it:edges){
            graph[it[0]].emplace_back(it[1],it[2]);
            graph[it[1]].emplace_back(it[0],it[2]);
        }
        
        vector<int>dist(V,INT_MAX);
        vector<long long> ways(V, 0);
        dist[0]=0;
        ways[0]=1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        // {dist,node}
        
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            
            int node=top.second;
            int distance=top.first;
            
            if(distance > dist[node]) continue;
            
            for(auto it:graph[node]){
                if(dist[it.first]>dist[node]+it.second){
                    dist[it.first]=dist[node]+it.second;
                    ways[it.first]=ways[node];
                    pq.push({dist[it.first],it.first});
                }else if(dist[it.first]==dist[node]+it.second){
                    ways[it.first]+=ways[node];
                }
            }
        }
        return ways[V-1];
    }
};