class Solution {
public:

    vector<int>visited;

    void dfs(int node,vector<vector<int>>&graph){
        int n=graph.size();
        visited[node]=1;

        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && !visited[i]){
                dfs(i,graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
        visited.resize(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected);
            }
        }
        return ans;
    }
};