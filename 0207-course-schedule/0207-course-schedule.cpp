class Solution {
public:

    vector<vector<int>>graph;
    vector<int>pathVisited;
    vector<int>visited;

    bool dfs(int node){
        visited[node]=1;
        pathVisited[node]=1;

        for(auto it:graph[node]){
            if(!visited[it]){
                if(dfs(it)) return true;
            }else if(pathVisited[it]) return true;
        }

        pathVisited[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        pathVisited.resize(numCourses);
        visited.resize(numCourses);

        for(auto it:prerequisites){
            graph[it[1]].emplace_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i)) return false;
            }
        }
        return true;
    }
};