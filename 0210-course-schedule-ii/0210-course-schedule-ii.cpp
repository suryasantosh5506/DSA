class Solution {
public:

    vector<int>visited;
    vector<int>pathVisited;
    vector<vector<int>>graph;
    vector<int>ans;
    stack<int>st;

    bool dfs(int node){
        visited[node]=1;
        pathVisited[node]=1;

        for(auto it:graph[node]){
            if(!visited[it]){
                if(dfs(it)) return true;
            }else if(pathVisited[it]) return true;
        }
        pathVisited[node]=0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        visited.resize(n,0);
        pathVisited.resize(n,0);
        graph.resize(n);

        for(auto it:prerequisites){
            graph[it[1]].emplace_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i)) return ans;
            }
        }

        while(!st.empty()){
            ans.emplace_back(st.top());
            st.pop();
        }

        return ans;
    }
};