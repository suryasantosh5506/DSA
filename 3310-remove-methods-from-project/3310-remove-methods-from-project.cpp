class Solution {
public:

    vector<vector<int>>graph;
    vector<int>visited;
    vector<int>checkvisited;

    void dfs(int node){
        visited[node]=1;

        for(auto it:graph[node]){
            if(!visited[it]) dfs(it);
        }
    }

    bool canInvoke(int node){
        checkvisited[node]=1;

        for(auto it:graph[node]){
            if(visited[it]) return true;
            if(!checkvisited[it]){
                if(canInvoke(it)) return true;
            }
        }
        return false;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        graph.resize(n);
        visited.resize(n,0);
        checkvisited.resize(n,0);
        for(auto it:invocations){
            graph[it[0]].emplace_back(it[1]);
        }
        dfs(k);
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(canInvoke(i)){
                    for(int i=0;i<n;i++) ans.emplace_back(i);
                    return ans;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]) ans.emplace_back(i);
        }
        
        return ans;
    }
};