// problem link:- https://www.geeksforgeeks.org/problems/course-schedule-i/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>>graph(n);
        vector<int>indegree(n),ans;
        for(auto it:prerequisites){
            graph[it[1]].emplace_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans.emplace_back(node);
            
            for(auto it:graph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans.size()==n;
    }
};