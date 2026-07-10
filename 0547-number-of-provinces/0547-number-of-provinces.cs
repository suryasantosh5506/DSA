public class Solution {

    int[] visited;

    public void dfs(int node,int[][] isConnected){
        visited[node]=1;
        int n=isConnected.Length;

        for(int i=0;i<n;i++){
            if(isConnected[node][i]==1 && visited[i]==0){
                visited[i]=1;
                dfs(i,isConnected);
            }
        }
    }

    public int FindCircleNum(int[][] isConnected) {
        int ans=0;
        int n=isConnected.Length;
        visited=new int[n];

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,isConnected);
                ans++;
            }
        }
        return ans;
    }
}