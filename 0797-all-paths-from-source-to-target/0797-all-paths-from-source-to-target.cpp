class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;
    vector<bool>visited;
    int n;

    void solution(int node,vector<vector<int>>&graph){
        if(node==n-1){
            seq.emplace_back(node);
            ans.emplace_back(seq);
            seq.pop_back();
            return;
        }

        seq.emplace_back(node);
        visited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                solution(it,graph);
            }
        }
        seq.pop_back();
        visited[node]=0;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        visited.assign(n,false);
        solution(0,graph);
        return ans;
    }
};