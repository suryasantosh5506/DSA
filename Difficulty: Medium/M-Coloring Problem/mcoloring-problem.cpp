class Solution {
  public:
  
    bool isSafe(int node,int color,vector<int>&colorTracer,vector<vector<int>>&graph){
        for(auto it:graph[node]){
            if(colorTracer[it]==color) return false;
        }
        return true;
    }
  
    bool solution(int node,int m,vector<int>&colorTracer,vector<vector<int>>&graph){
        if(node==colorTracer.size()){
            return true;
        }
        
        for(int i=1;i<=m;i++){
            if(isSafe(node,i,colorTracer,graph)){
                colorTracer[node]=i;
                if(solution(node+1,m,colorTracer,graph)) return true;
                colorTracer[node]=0;
            }
        }
        
        return false;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int>colorTracer(v,0);
        vector<vector<int>>graph(v);
        for(auto it:edges){
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }
        return solution(0,m,colorTracer,graph);
    }
};