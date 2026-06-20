class Solution {
public:

    int n;
    vector<int>visited;

    void dfs(int i,vector<vector<int>>&graph){
        visited[i]=1;

        for(int j=0;j<n;j++){
            if(graph[i][j]==1 && !visited[j]){
                dfs(j,graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       n=isConnected.size();
       visited.assign(n,0) ;
       int cnt=0;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i,isConnected);
        }
       }
       return cnt;
    }
};