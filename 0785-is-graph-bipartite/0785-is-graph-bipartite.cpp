class Solution {
public:

    vector<int>colorTracer;
    int n;

    bool dfs(int node,int color,vector<vector<int>>& graph){
        colorTracer[node]=color;

        for(auto it:graph[node]){
            if(colorTracer[it]==-1){
                if(!dfs(it,!color,graph)) return false;
            }else if(colorTracer[it]==color)  return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        colorTracer.resize(n,-1);
        for(int i=0;i<n;i++){
            if(colorTracer[i]==-1){
                if(!dfs(i,0,graph)) return false;
            }
        }
        return true;
    }
};