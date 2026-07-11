public class Solution {

    List<List<int>>graph;
    int[] visited;
    int n;

    public void dfs(int node,ref List<int>component){
        visited[node]=1;
        component.Add(node);

        foreach(var it in graph[node]){
            if(visited[it]==0){
                dfs(it,ref component);
            }
        }
    }

    public int CountCompleteComponents(int n, int[][] edges) {
        graph=new List<List<int>>();
        int ans=0;
        this.n=n;
        visited=new int[n];
        for(int i=0;i<n;i++){
            graph.Add(new List<int>());
        }

        foreach(var it in edges){
            graph[it[0]].Add(it[1]);
            graph[it[1]].Add(it[0]);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                List<int>component=new List<int>();
                dfs(i,ref component);

                int noofedges=0;

                foreach(var x in component){
                    noofedges+=graph[x].Count;
                }
                noofedges/=2;
                int nodes=component.Count;
                if(noofedges==(nodes*(nodes-1))/2){
                    ans++;
                }
            }
        }
        return ans;
    }
}