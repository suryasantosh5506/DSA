class Solution {
public:

    vector<vector<pair<int,int>>>graph;
    int ans=INT_MAX;
    vector<int>visited;

    void dfs(int node){
        visited[node]=1;
        
        for(auto it:graph[node]){
            ans=min(ans,it.second);
            if(!visited[it.first]){
                dfs(it.first);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        graph.resize(n+1);
        visited.resize(n+1,0);
        for(auto &x:roads){
            graph[x[0]].emplace_back(x[1],x[2]);
            graph[x[1]].emplace_back(x[0],x[2]);
        }
        dfs(1);
        return ans;
    }
};