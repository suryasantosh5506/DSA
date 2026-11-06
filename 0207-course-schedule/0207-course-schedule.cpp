class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto it:edges){
            graph[it[1]].emplace_back(it[0]);
        }

        vector<int>visited(n,0);
        vector<int>pathvisited(n,0);

        function<bool(int)>dfs=[&](int node){
            visited[node]=1;
            pathvisited[node]=1;

            for(auto it:graph[node]){
                if(!visited[it]){
                    if(dfs(it)) return true;
                }else if(pathvisited[it]) return true;
            }
            
            pathvisited[node]=0;
            return false;
        };

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i)) return false;
            }
        }

        return true;
    }
};